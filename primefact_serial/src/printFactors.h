// Copyright 2021 Luis Fernando Gomez Sanchez C03309

#ifndef PRINTFACTORS_H_
#define PRINTFACTORS_H_
#include "structures.h"

/**
 * @brief Evalua si un numero dado es un numero primo o no
 * @param number numero que se desea saber si es primo o no
 * @return condicion boleana:
 *   true si el numero recibido por parametro es primo
 *   false si el numero recibido por parametro no es primo
 */
void printPrimeFactors(number* number);

/**
 * @brief Evalua si un numero dado es un numero primo o no
 * @param number numero que se desea saber si es primo o no
 * @return condicion boleana:
 *   true si el numero recibido por parametro es primo
 *   false si el numero recibido por parametro no es primo
 */
void printFactorization(numberList* numberList);

#endif  // PRINTFACTORS_H_
