// Copyright 2021 Luis Fernando Gomez Sanchez C03309

#include "printFactors.h"
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdint.h>
#include <omp.h>
#include "structures.h"

void printFactorization(numberList* numberList, int64_t threadCount,
                        int64_t numberCount) {
  number* auxiliarNumber = numberList->firstNumber;
  number* actualNumber;
  #pragma omp parallel for default(none) num_threads(threadCount) \
    shared(numberList, auxiliarNumber, numberCount) private(actualNumber)
    for (int64_t forCount = 0; forCount < numberCount; forCount++) {
      #pragma omp critical
      {
        actualNumber = auxiliarNumber;
        auxiliarNumber = auxiliarNumber->nextNumber;
        int64_t printCondition = actualNumber->firstFactor->factorValue;
        if (printCondition == 0) {
          printf("invalid number\n");
        } else {
          printf("%" PRId64 ":", actualNumber->value);
          if (printCondition == 1) {
            printf(" NA\n");
          } else if (printCondition != -1) {
            printPrimeFactors(actualNumber);
          } else {
            printf(" invalid number\n");
          }
        }
      }
    }
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
