// Copyright 2021 Luis Fernando Gomez Sanchez C03309

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "readerNumbers.h"
#include "structures.h"
#include "threadStructures.h"
#include "factorization.h"
#include "printFactors.h"

int main(int argc, char* argv[]) {
  uint64_t threadCount = sysconf(_SC_NPROCESSORS_ONLN);
  int64_t error = EXIT_SUCCESS;
  if (argc == 2) {
    if (sscanf(argv[1], "%" SCNu64, &threadCount) == 1) {
    } else {
      fprintf(stderr, "Error: Cantidad inválida de hilos\n");
      return EXIT_FAILURE;
    }
  }
  numberList* list = (numberList*) malloc(sizeof(numberList));
  initNumberListNode(list);
  sharedData* sharedThreadsData = (sharedData*) calloc(1, sizeof(sharedData));
  if (sharedThreadsData && list) {
    int64_t numberCount = readerNumbers(list);
    sharedThreadsData->threadCount = threadCount;
    sharedThreadsData->numberCount = numberCount;
    int64_t error = createThreads(list, sharedThreadsData);
    if (error == EXIT_SUCCESS) {
      printFactorization(list, sharedThreadsData);
    }
  } else {
    fprintf(stderr, "Error: No es posible alojar memoria\n");
    return EXIT_FAILURE;
  }
  free(sharedThreadsData);
  destroyList(list);
  return error;
}
