// Copyright 2021 Luis Fernando Gomez Sanchez C03309

#include <stdlib.h>
#include "readerNumbers.h"
#include "structures.h"
#include "factorization.h"
#include "printFactors.h"

int main(void) {
  numberList* list = (numberList*) malloc(sizeof(numberList));
  initNumberListNode(list);
  readerNumbers(list);
  calculateFactors(list);
  printFactorization(list);
  destroyList(list);
  return 0;
}
