// Copyright 2021 Luis Fernando Gomez Sanchez C03309

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include <omp.h>
#include "structures.h"
#include "factorization.h"

void primeFactors(number* number) {
  // Print the number of 2s that divide n
  int64_t numberValue = number->value;
  while (numberValue % 2 == 0) {
    if (number->lastFactor == NULL) {
      addFactor(number, 2);
    } else if (number->lastFactor->factorValue == 2) {
      ++(number->lastFactor->exponent);
    } else {
      addFactor(number, 2);
    }
    numberValue /= 2;
  }

  // n must be odd at this point.  So we can skip
  // one element (Note i = i +2)
  for (int i = 3; i <= sqrt(numberValue); i = i + 2) {
    // While i divides n, print i and divide n
    while (numberValue % i == 0) {
      if (number->lastFactor == NULL) {
        addFactor(number, i);
      } else if (number->lastFactor->factorValue == i) {
        ++(number->lastFactor->exponent);
      } else {
        addFactor(number, i);
      }
      numberValue /= i;
    }
  }

  // This condition is to handle the case when n
  // is a prime number greater than 2
  if (numberValue > 2) {
      addFactor(number, numberValue);
  }
}

void calculateFactors(numberList* numberList, int64_t threadCount,
                      int64_t numberCount) {
  number* auxiliarNode = numberList->firstNumber;
  number* actualNumber;

  #pragma omp parallel for default(none) num_threads(threadCount) \
    shared(numberList, auxiliarNode, numberCount) private(actualNumber) \
    schedule(guided)
    for (int64_t forCount = 0; forCount < numberCount; forCount++) {
      #pragma omp critical
      {
        actualNumber = auxiliarNode;
        auxiliarNode = auxiliarNode->nextNumber;
      }

      int64_t numberValue = actualNumber->value;
      if (numberValue > 1) {
        primeFactors(actualNumber);

      } else if (numberValue == 1 || (numberValue == 0
                 && actualNumber->error == 0)) {
        addFactor(actualNumber, 1);
      } else if (numberValue == 0 && actualNumber->error == 1) {
        addFactor(actualNumber, 0);
      } else {
        addFactor(actualNumber, -1);
      }
    }
}

