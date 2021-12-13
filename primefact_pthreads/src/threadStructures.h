// Copyright 2021 Luis Fernando Gomez Sanchez C03309

#ifndef THREADSTRUCTURES_H_
#define THREADSTRUCTURES_H_

#include <inttypes.h>
#include <stdint.h>
#include "structures.h"

typedef struct sharedData {
  int64_t nextThread;
  int64_t threadCount;
  int64_t numberCount;
  number* nextNumber;
} sharedData;

typedef struct privateData {
  int64_t thread;
  number* number;
  sharedData* sharedData;
} privateData;

#endif  // THREADSTRUCTURES_H_
