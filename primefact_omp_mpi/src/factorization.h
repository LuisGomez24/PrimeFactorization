// Copyright 2021 Luis Fernando Gomez Sanchez C03309
// Adaptado de <https://github.com/Fhernd/JavaScriptEjercicios/blob/master/Parte001/ex787-factores-primos-unicos-numero-funcion.js>

#ifndef FACTORIZATION_H_
#define FACTORIZATION_H_

#include <inttypes.h>
#include <stdint.h>
#include <stdbool.h>
#include "structures.h"

/**
 * @brief Calcula los factores primos de un numero
 * @param number numero que se factorizara
 */
void primeFactors(number* number);

/**
 * @brief Calcula los factores primos de cada numero de forma concurrente
 * @param numberList lista con los numeros que se factorizaran
 * @param threadCount cantidad de hilos que se usaran
 * @param numberCount cantidad de numeros a factorizar
 * @details Esta funcion utiliza la tecnologia de OpenMP para realizar la
 *          factorizacion prima de cada numero ingresado.
 */
void calculateFactors(numberList* numberList, int64_t threadCount,
                      int64_t numberCount);

#endif  // FACTORIZATION_H_
