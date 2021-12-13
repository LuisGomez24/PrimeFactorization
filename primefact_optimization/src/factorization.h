// Copyright 2021 Luis Fernando Gomez Sanchez C03309
// Versión Optimización 1 adaptado de <https://github.com/Fhernd/JavaScriptEjercicios/blob/master/Parte001/ex787-factores-primos-unicos-numero-funcion.js>
// Versión Optimización 2 adaptado de <https://www.geeksforgeeks.org/print-all-prime-factors-of-a-given-number/?ref=lbp>

#ifndef FACTORIZATION_H_
#define FACTORIZATION_H_

#include <inttypes.h>
#include <stdint.h>
#include <stdbool.h>
#include "structures.h"
#include "threadStructures.h"

/**
 * @brief Evalua si un numero dado es un numero primo o no
 * @param number numero que se desea saber si es primo o no
 * @return condicion boleana:
 *   true si el numero recibido por parametro es primo
 *   false si el numero recibido por parametro no es primo
 */
bool isPrime(int64_t number);

/**
 * @brief Calcula los primos de un numero dado
 * @param data datos privados del hilo en ejecución
 * @details Esta función utiliza el descarte de pares y llega hasta el
 *          valor de la raiz cuadrada del número a factorizar, por lo que
 *          reduce considerablemente las iteraciones del anterior método.
 */
void primeFactors(privateData* data);

/**
 * @brief Calcula los factores primos de cada numero de forma concurrente
 * @param numberList lista con los numeros que se factorizaran
 * @param sharedThreadsData struct con los datos compartidos de los hilos
 * @details Esta funcion realiza la creación de los hilos y procede a
 *          dividir los números de forma cíclica hasta completar los hilos,
 *          así cada hilo hace la factorización de un número en específico
 *          para luego volver a crear hilos con más números hasta completarlos.
 */
int64_t createThreads(numberList* list, sharedData* sharedThreadsData);

#endif  // FACTORIZATION_H_
