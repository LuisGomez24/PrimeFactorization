// Copyright 2021 Luis Fernando Gomez Sanchez C03309

#ifndef PRINTFACTORS_H_
#define PRINTFACTORS_H_

#include <inttypes.h>
#include <stdint.h>
#include "structures.h"
#include "threadStructures.h"

/**
 * @brief Imprime la factorización prima de los números ingresados
 * @param data data privada con los datos del hilo
 */
void* printPrimeFactors(void* data);

/**
 * @brief Imprime la factorización prima de los números ingresados
 * @param numberList lista con los números a imprimir
 * @param shared data compartida entre los hilos dados.
 * @return EXIT_SUCCESS si no hay errores, número del error en caso contrario
 */
int64_t printFactorization(numberList* numberList, sharedData* shared);

#endif  // PRINTFACTORS_H_
