// Copyright 2021 Luis Fernando Gomez Sanchez C03309

#ifndef PRINTFACTORS_H_
#define PRINTFACTORS_H_

#include <inttypes.h>
#include <stdint.h>
#include "structures.h"

/**
 * @brief Imprime la factorización prima de un numero dado
 * @param number numero al que se le imprimiran sus factores primos
 */
void printPrimeFactors(number *number);

/**
 * @brief Imprime la factorización prima de los números ingresados
 * @param numberList lista con los números a imprimir
 * @param threadCount cantidad de hilos a crear
 * @param numberCount cantidad de numeros a imprimir
 */
void printFactorization(numberList* numberList, int64_t threadCount,
                        int64_t numberCount);

#endif  // PRINTFACTORS_H_
