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

bool isPrime(int64_t number) {
  for ( int64_t divisors = 2; divisors <= sqrt(number); divisors++ ) {
    if (number % divisors == 0) {
      return false;
    }
  }
  return true;
}

void* factorization(void* data) {
  privateData* dataNumber = (privateData*) data;
  int64_t numberValue = dataNumber->number->value;
  int64_t error = dataNumber->number->error;
  if (numberValue > 1) {
    int64_t currentFactor = 0;
    for (currentFactor = 2; currentFactor <= numberValue; currentFactor++) {
      if (isPrime(currentFactor) && (numberValue % currentFactor) == 0) {
        if (dataNumber->number->lastFactor == NULL) {
          addFactor(dataNumber->number, currentFactor);
        } else if (dataNumber->number->lastFactor->factorValue
           == currentFactor) {
          ++(dataNumber->number->lastFactor->exponent);
        } else {
          addFactor(dataNumber->number, currentFactor);
        }
        numberValue /= currentFactor;
        if ((numberValue % currentFactor) == 0) {
          --currentFactor;
        }
      }
    }
  } else if (numberValue == 1 || (numberValue == 0 && error == 0)) {
    addFactor(dataNumber->number, 1);
  } else if (numberValue == 0 && error == 1) {
    addFactor(dataNumber->number, 0);
  } else {
    addFactor(dataNumber->number, -1);
  }
  return NULL;
}

int64_t createThreads(numberList* list, sharedData* sharedThreadsData) {
  number* auxiliarNumber = list->firstNumber;
  int64_t threadsCount = sharedThreadsData->threadCount;
  int64_t actualNumber = 0;
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

  while (auxiliarNumber != NULL) {
    privateDataThreads[actualNumber].number = auxiliarNumber;
    privateDataThreads[actualNumber].thread = actualNumber;
    privateDataThreads[actualNumber].sharedData = sharedThreadsData;
    int64_t error = pthread_create(&threads[actualNumber], NULL,
      factorization, &privateDataThreads[actualNumber]);
    if (error == EXIT_SUCCESS) {
    } else {
      fprintf(stderr, "Error: No es posible crear hilo secundario\n");
      error = 23;
      break;
    }
    if (actualNumber == threadsCount - 1) {
      for (int64_t lastJoin = 0; threadsCount > lastJoin; lastJoin++) {
        pthread_join(threads[lastJoin], NULL);
      }
      actualNumber = -1;
    }
    auxiliarNumber = auxiliarNumber->nextNumber;
    ++actualNumber;
  }
  if (actualNumber > 0) {
    for (int64_t lastJoin = 0; actualNumber > lastJoin; lastJoin++) {
      pthread_join(threads[lastJoin], NULL);
    }
  }
  free(privateDataThreads);
  free(threads);
  return error;
}
