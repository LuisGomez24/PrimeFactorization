// Copyright 2021 Luis Fernando Gomez Sanchez C03309

#include "readerNumbers.h"
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdint.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>
#include "structures.h"

int64_t readerNumbers(numberList* listNumbers) {
  int64_t numberCount = 0;
  while (true) {
    int64_t value = 0;
    errno = 0;
    fflush(stdin);
    int scan = scanf(" %" SCNd64, &value);
    if (errno == 0 && scan == 1) {
        int condition = 0;
        int caracter = fgetc(stdin);
        while (feof(stdin) != 1 && caracter != '\n') {
        // while (caracter != EOF && caracter != '\n') {
            if (caracter > '9' || caracter < '0') {
                condition = 1;
            }
            caracter = fgetc(stdin);
        }
        if (condition == 0) {
          addNumber(listNumbers, value);
          ++numberCount;
        } else {
          addNumberError(listNumbers);
          ++numberCount;
        }
        // if (caracter == EOF) {
        if (feof(stdin)) {
          break;
        }
    } else {
      if (feof(stdin) == 1) {
        break;
      } else if (errno == ERANGE) {
        addNumberError(listNumbers);
        ++numberCount;
      } else {
        int caracter = fgetc(stdin);
        while (feof(stdin) != 1 && caracter != '\n') {
            caracter = fgetc(stdin);
        }
        if (caracter == '\n') {
          addNumberError(listNumbers);
          ++numberCount;
        } else if (feof(stdin)) {
          break;
        }
      }
    }
  }
  return numberCount;
}
