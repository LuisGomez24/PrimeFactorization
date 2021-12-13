// Copyright 2021 Luis Fernando Gomez Sanchez C03309

#include "printFactors.h"
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdint.h>
#include <pthread.h>
#include "structures.h"
#include "threadStructures.h"

void* printPrimeFactors(void* data);

int64_t printFactorization(numberList* list, sharedData* shared) {
  int64_t threadsCount = shared->threadCount;
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

  for (int64_t thread = 0; thread < shared->threadCount; thread++) {
    error = sem_init(&shared->canAccessNode[thread], /*pshared*/ 0
      , /*value*/ !thread);
    if (error == EXIT_SUCCESS) {
      privateDataThreads[thread].number = shared->number;
      privateDataThreads[thread].thread = thread;
      privateDataThreads[thread].sharedData = shared;
      if (shared->number != NULL) {
        shared->number = shared->number->nextNumber;
      }
      error = pthread_create(&threads[thread], NULL,
        printPrimeFactors, &privateDataThreads[thread]);
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

  for (int64_t thread = 0; thread < shared->threadCount; thread++) {
    pthread_join(threads[thread], NULL);
    sem_destroy(&shared->canAccessNode[thread]);
  }
  free(privateDataThreads);
  free(threads);

  return error;
}

void* printPrimeFactors(void* data) {
  privateData* threadData = (privateData*) data;
  while (threadData->number != NULL) {
    int64_t numberValue = threadData->number->value;
    int64_t printCondition = threadData->number->firstFactor->factorValue;
    sem_wait(&threadData->sharedData->canAccessNode[threadData->thread]);
    if (printCondition == 0) {
      printf("invalid number\n");
    } else {
      printf("%" PRId64 ":", numberValue);
      if (printCondition == 1) {
        printf(" NA\n");
      } else if (printCondition != -1) {
        factor* currentFactor = threadData->number->firstFactor;
        while (currentFactor != NULL) {
          printf(" %" PRId64, currentFactor->factorValue);
          if (currentFactor->exponent != 1) {
            printf("^%" PRId64, currentFactor->exponent);
          }
          currentFactor = currentFactor->nextFactor;
        }
        printf("\n");
      } else {
        printf(" invalid number\n");
      }
    }
    // sem_wait(&threadData->sharedData->canAccessNode[threadData->thread]);
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

