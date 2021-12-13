// Copyright 2021 Luis Fernando Gomez Sanchez C03309

#include "printFactors.h"
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdint.h>
#include <pthread.h>
#include "structures.h"
#include "threadStructures.h"

int64_t printFactorization(numberList* list, sharedData* shared) {
  number* auxiliarNumber = list->firstNumber;
  int64_t threadsCount = shared->threadCount;
  int64_t error = EXIT_SUCCESS;
  pthread_t* threads = (pthread_t*) malloc(threadsCount * sizeof(pthread_t));
  privateData* privateDataThreads = (privateData*)
    calloc(threadsCount, sizeof(privateData));

  if (threads == NULL) {
    fprintf(stderr, "Error: No es posible reservar memoria para pthreads\n");
    destroyList(list);
    error = EXIT_FAILURE;
  } else if (privateDataThreads == NULL) {
    fprintf(stderr,
      "Error: No es posible reservar memoria para data privada\n");
    destroyList(list);
    error = EXIT_FAILURE;
  } else {
    while (auxiliarNumber != NULL) {
      int64_t printCondition = auxiliarNumber->firstFactor->factorValue;
      if (printCondition == 0) {
        printf("invalid number\n");
      } else {
        printf("%" PRId64 ":", auxiliarNumber->value);
        if (printCondition == 1) {
          printf(" NA\n");
        } else if (printCondition != -1) {
          printPrimeFactors(auxiliarNumber);
        } else {
          printf(" invalid number\n");
        }
      }
      auxiliarNumber = auxiliarNumber->nextNumber;
    }
  }

  return error;
}

void printPrimeFactors(number* number) {
  factor* currentFactor = number->firstFactor;
  while (currentFactor != NULL) {
    printf(" %" PRId64, currentFactor->factorValue);
    if (currentFactor->exponent != 1) {
      printf("^%" PRId64, currentFactor->exponent);
    }
    currentFactor = currentFactor->nextFactor;
  }
  printf("\n");
}

