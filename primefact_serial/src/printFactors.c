// Copyright 2021 Luis Fernando Gomez Sanchez C03309

#include "printFactors.h"
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdint.h>
#include "structures.h"

void printFactorization(numberList* numberList) {
  number* auxiliarNumber = numberList->firstNumber;
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
