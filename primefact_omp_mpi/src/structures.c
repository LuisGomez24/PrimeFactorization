// Copyright 2021 Luis Fernando Gomez Sanchez C03309

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdint.h>
#include "structures.h"

void initFactorNode(factor* factor, int64_t value) {
  factor->factorValue = value;
  factor->exponent = 1;
  factor->nextFactor = NULL;
}

void initNumberNode(number* number, int64_t value) {
  number->value = value;
  number->error = 0;
  number->firstFactor = NULL;
  number->lastFactor = NULL;
  number->nextNumber = NULL;
}

void initNumberNodeError(number* number) {
  number->value = 0;
  number->error = 1;
  number->firstFactor = NULL;
  number->lastFactor = NULL;
  number->nextNumber = NULL;
}

void initNumberListNode(numberList* list) {
  list->firstNumber = NULL;
  list->lastNumber = NULL;
}

void addFactor(number* number, int64_t value) {
  factor* newFactor = (factor*) malloc(sizeof(factor));
  if (newFactor == NULL) {
    fprintf(stderr, "Error: No ha sido posible reservar memoria para factor\n");
    exit(EXIT_FAILURE);
  }
  initFactorNode(newFactor, value);
  if (number->firstFactor == NULL) {
    number->firstFactor = newFactor;
    number->lastFactor = newFactor;
  } else if (number->lastFactor != NULL) {
    number->lastFactor->nextFactor = newFactor;
    number->lastFactor = newFactor;
  } else {
    exit(EXIT_FAILURE);
  }
}

void addNumber(numberList* list, int64_t value) {
  number* newNumber = (number*) malloc(sizeof(number));
  if (newNumber == NULL) {
    fprintf(stderr, "Error: No ha sido posible reservar memoria para número\n");
    exit(EXIT_FAILURE);
  }
  initNumberNode(newNumber, value);
  if (list->firstNumber == NULL) {
    list->firstNumber = newNumber;
    list->lastNumber = newNumber;
  } else {
    list->lastNumber->nextNumber = newNumber;
    list->lastNumber = newNumber;
  }
}

void addNumberError(numberList* list) {
  number* newNumber = (number*) malloc(sizeof(number));
  if (newNumber == NULL) {
    fprintf(stderr, "Error: No ha sido posible reservar memoria para número\n");
    exit(EXIT_FAILURE);
  }
  initNumberNodeError(newNumber);
  if (list->firstNumber == NULL) {
    list->firstNumber = newNumber;
    list->lastNumber = newNumber;
  } else {
    list->lastNumber->nextNumber = newNumber;
    list->lastNumber = newNumber;
  }
}

void destroyFactor(factor* rootFactor) {
    factor* currentFactor = rootFactor;
     while (currentFactor != NULL) {
      factor* factorToFree = currentFactor;
      currentFactor = currentFactor->nextFactor;
      free(factorToFree);
    }
}

void destroyNumber(number* rootNumber) {
  number* currentNumber = rootNumber;
    while (currentNumber != NULL) {
      number* numberToFree = currentNumber;
      currentNumber = currentNumber->nextNumber;
      destroyFactor(numberToFree->firstFactor);
      free(numberToFree);
    }
}

void destroyList(numberList* list) {
  if (list->firstNumber != NULL) {
    destroyNumber(list->firstNumber);
  } else {
    free(list->firstNumber);
    free(list->lastNumber);
  }
  free(list);
}
