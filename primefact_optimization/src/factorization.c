// Copyright 2021 Luis Fernando Gomez Sanchez C03309

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include <pthread.h>
#include "structures.h"
#include "factorization.h"
#include "threadStructures.h"

void* factorization(void* data);

/*Versión Optimización 2*/
void primeFactors(privateData* data) {
  // Print the number of 2s that divide n
  int64_t number = data->number->value;
  while (number % 2 == 0) {
    if (data->number->lastFactor == NULL) {
      addFactor(data->number, 2);
    } else if (data->number->lastFactor->factorValue == 2) {
      ++(data->number->lastFactor->exponent);
    } else {
      addFactor(data->number, 2);
    }
    number /= 2;
  }

  // n must be odd at this point.  So we can skip
  // one element (Note i = i +2)
  for (int i = 3; i <= sqrt(number); i = i + 2) {
    // While i divides n, print i and divide n
    while (number % i == 0) {
      if (data->number->lastFactor == NULL) {
        addFactor(data->number, i);
      } else if (data->number->lastFactor->factorValue == i) {
        ++(data->number->lastFactor->exponent);
      } else {
        addFactor(data->number, i);
      }
      number /= i;
    }
  }

  // This condition is to handle the case when n
  // is a prime number greater than 2
  if (number > 2) {
      addFactor(data->number, number);
  }
}

/* Version Optimización 1*/
/*bool isPrime(int64_t number) {
  for ( int64_t divisors = 2; divisors <= sqrt(number); divisors++ ) {
    if (number % divisors == 0) {
      return false;
    }
  }
  return true;
}*/

void* factorization(void* data) {
  privateData* threadData = (privateData*) data;
  // sem_wait(&threadData->sharedData->canAccessNode[threadData->thread]);
  while (threadData->number != NULL) {
    int64_t numberValue = threadData->number->value;
    int64_t error = threadData->number->error;
    if (numberValue > 1) {
      /* Version Optimización 1*/
      /*int64_t currentFactor = 0;
      for (currentFactor = 2; currentFactor <= numberValue; currentFactor++) {
        if (isPrime(currentFactor) && (numberValue % currentFactor) == 0) {
          if (threadData->number->lastFactor == NULL) {
            addFactor(threadData->number, currentFactor);
          } else if (threadData->number->lastFactor->factorValue
            == currentFactor) {
            ++(threadData->number->lastFactor->exponent);
          } else {
            addFactor(threadData->number, currentFactor);
          }
          numberValue /= currentFactor;
          if ((numberValue % currentFactor) == 0) {
            --currentFactor;
          }
        }
      }*/
      primeFactors(threadData);
    } else if (numberValue == 1 || (numberValue == 0 && error == 0)) {
      addFactor(threadData->number, 1);
    } else if (numberValue == 0 && error == 1) {
      addFactor(threadData->number, 0);
    } else {
      addFactor(threadData->number, -1);
    }
    sem_wait(&threadData->sharedData->canAccessNode[threadData->thread]);
    threadData->number = threadData->sharedData->number;
    if (threadData->sharedData->number != NULL) {
      threadData->sharedData->number = threadData->number->nextNumber;
    }
    const uint64_t nextThread = (threadData->thread + 1)
      % threadData->sharedData->threadCount;
    sem_post(&threadData->sharedData->canAccessNode[nextThread]);
  }

  return NULL;
}

int64_t createThreads(numberList* list, sharedData* sharedThreadsData) {
  int64_t threadsCount = sharedThreadsData->threadCount;
  int64_t error = EXIT_SUCCESS;
  pthread_t* threads = (pthread_t*) malloc(threadsCount * sizeof(pthread_t));
  privateData* privateDataThreads = (privateData*)
    calloc(threadsCount, sizeof(privateData));
  if (threads == NULL) {
    fprintf(stderr, "Error: No es posible reservar memoria para pthreads\n");
    destroyList(list);
    exit(EXIT_FAILURE);
  } else if (privateDataThreads == NULL) {
    fprintf(stderr,
      "Error: No es posible reservar memoria para data privada\n");
    destroyList(list);
    exit(EXIT_FAILURE);
  }

  for (int64_t thread = 0; thread < sharedThreadsData->threadCount; thread++) {
    error = sem_init(&sharedThreadsData->canAccessNode[thread], /*pshared*/ 0
      , /*value*/ !thread);
    if (error == EXIT_SUCCESS) {
      privateDataThreads[thread].number = sharedThreadsData->number;
      privateDataThreads[thread].thread = thread;
      privateDataThreads[thread].sharedData = sharedThreadsData;
      if (sharedThreadsData->number != NULL) {
        sharedThreadsData->number = sharedThreadsData->number->nextNumber;
      }
      error = pthread_create(&threads[thread], NULL,
        factorization, &privateDataThreads[thread]);
      if (error == EXIT_SUCCESS) {
      } else {
        fprintf(stderr, "Error: No es posible crear hilo secundario\n");
        error = 23;
        break;
      }
    } else {
      fprintf(stderr, "Error: No es posible inicializar el semáforo\n");
      error = 22;
      break;
    }
  }

  for (int64_t thread = 0; thread < sharedThreadsData->threadCount; thread++) {
    pthread_join(threads[thread], NULL);
    sem_destroy(&sharedThreadsData->canAccessNode[thread]);
  }

  free(privateDataThreads);
  free(threads);
  return error;
}
