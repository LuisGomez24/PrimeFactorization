// Copyright 2021 Luis Fernando Gomez Sanchez C03309

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "readerNumbers.h"
#include "structures.h"
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

  // Clock inicio
  struct timespec start_time, finish_time;
  clock_gettime(CLOCK_MONOTONIC, &start_time);

  numberList* list = (numberList*) malloc(sizeof(numberList));
  initNumberListNode(list);
  int64_t numberCount = readerNumbers(list);
  calculateFactors(list, threadCount, numberCount);
  printFactorization(list, threadCount, numberCount);

  // Clock final
  clock_gettime(CLOCK_MONOTONIC, &finish_time);
  double elapsed_time = finish_time.tv_sec - start_time.tv_sec
    + (finish_time.tv_nsec - start_time.tv_nsec) * 1e-9;
  fprintf(stderr, "Execution time: %.9lfs\n", elapsed_time);

  destroyList(list);
  return error;
}
