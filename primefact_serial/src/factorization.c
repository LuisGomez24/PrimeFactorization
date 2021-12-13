// Copyright 2021 Luis Fernando Gomez Sanchez C03309

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include "structures.h"
#include "factorization.h"

bool isPrime(int64_t number) {
  for ( int64_t divisors = 2; divisors <= sqrt(number); divisors++ ) {
    if (number % divisors == 0) {
      return false;
    }
  }
  return true;
}

void calculateFactorsOfNumber(number* number) {
  int64_t numberValue = number->value;
  if (numberValue > 1) {
    int64_t currentFactor;
    for (currentFactor = 2; currentFactor <= numberValue; currentFactor++) {
      if (isPrime(currentFactor) && (number->value % currentFactor) == 0) {
        if (number->lastFactor == NULL) {
          addFactor(number, currentFactor);
        } else if (number->lastFactor->factorValue == currentFactor) {
          ++(number->lastFactor->exponent);
        } else {
          addFactor(number, currentFactor);
        }
        numberValue /= currentFactor;
        if ((numberValue % currentFactor) == 0) {
          --currentFactor;
        }
      }
    }
  } else if (numberValue == 1 || (numberValue == 0 && number->error == 0)) {
    addFactor(number, 1);
  } else if (numberValue == 0 && number->error == 1) {
    addFactor(number, 0);
  } else {
    addFactor(number, -1);
  }
}

void calculateFactors(numberList* numberList) {
  number* auxiliarNode = numberList->firstNumber;
  while (auxiliarNode != NULL) {
    calculateFactorsOfNumber(auxiliarNode);
    auxiliarNode = auxiliarNode->nextNumber;
  }
}
