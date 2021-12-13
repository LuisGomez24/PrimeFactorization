// Copyright 2021 Luis Fernando Gomez Sanchez C03309

#ifndef READERNUMBERS_H_
#define READERNUMBERS_H_

#include <inttypes.h>
#include <stdint.h>
#include "structures.h"

/**
 * @brief Lee de la entrada estandar los numero a guardar
 * @details Realiza una lectura de la entrada estandar y va guardando en
 *          una lista enlazada el numero ingresado. Realiaz una evaluacion
 *          para saber si este valor ingresado es un numero o no.
 * @return cantidad de numeros y errores leidos
 */
int64_t readerNumbers(numberList* listNumbers);

#endif  // READERNUMBERS_H_
