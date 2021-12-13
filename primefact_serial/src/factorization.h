// Copyright 2021 Luis Fernando Gomez Sanchez C03309
// Adaptado de <https://github.com/Fhernd/JavaScriptEjercicios/blob/master/Parte001/ex787-factores-primos-unicos-numero-funcion.js>

#ifndef FACTORIZATION_H_
#define FACTORIZATION_H_
#include <inttypes.h>
#include <stdint.h>
#include <stdbool.h>
#include "structures.h"

/**
 * @brief Evalua si un numero dado es un numero primo o no
 * @param number numero que se desea saber si es primo o no
 * @return condicion boleana:
 *   true si el numero recibido por parametro es primo
 *   false si el numero recibido por parametro no es primo
 */
bool isPrime(int64_t number);

/**
 * @brief Calcula los factores primos de cada numero en la lista
 * @param numberList lista con los numeros que se factorizaran
 */
void calculateFactors(numberList* numberList);

#endif  // FACTORIZATION_H_
