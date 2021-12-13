// Copyright 2021 Luis Fernando Gomez Sanchez C03309

#ifndef STRUCTURES_H_
#define STRUCTURES_H_

#include <inttypes.h>
#include <stdint.h>

typedef struct factor factor;
typedef struct number number;

typedef struct factor {
  int64_t factorValue;
  int64_t exponent;
  factor* nextFactor;
} factor;

typedef struct number {
  int64_t value;
  int64_t error;
  factor* firstFactor;
  factor* lastFactor;
  number* nextNumber;
} number;

typedef struct numberList {
  number* firstNumber;
  number* lastNumber;
} numberList;

/**
 @brief Inicializa los valores de un nodo @a factor
 @param factor con un nodo @a factor inicializado
 @param value valor de un @a factor inicializado
*/
void initFactorNode(factor* factor, int64_t value);

/**
 @brief Inicializa los valores de un @a number
 @param number con un nodo @a number inicializado
 @param value valor de un @a number inicializado
*/
void initNumberNode(number* number, int64_t value);

/**
 @brief Inicializa los valores de un @a number con error
 @param number con un nodo @a number inicializado
*/
void initNumberNodeError(number* number);

/**
 @brief Inicializa los valores de un nodo @a numberList
 @param numberList con un nodo @a numberList inicializado
*/
void initNumberListNode(numberList* numberList);

/**
 @brief Libera el espacio reservado para @a numberList
 @param numberList con un nodo @a numberList inicializado
*/
void destroyList(numberList* numberList);

/**
 @brief Libera el espacio reservado para @a number
 @param number con un nodo @a number inicializado
*/
void destroyNumber(number* number);

/**
 @brief Libera el espacio reservado para @a factor
 @param factor con un nodo @a factor inicializado
*/
void destroyFactor(factor* factor);

/**
 @brief Agrega un factor a la lista de @a number
 @param number con el nodo @a number inicializado
 @param value valor del @a factor por agregar
*/
void addFactor(number* number, int64_t value);

/**
 @brief Agrega un numero a la lista de @a numberList
 @param list con el puntero @a numberList inicializado
 @param value valor del @a number por agregar
*/
void addNumber(numberList* list, int64_t value);

/**
 @brief Agrega un numero 0 con error a la lista de @a numberList
 @param list con el puntero @a numberList inicializado
*/
void addNumberError(numberList* list);

#endif  // STRUCTURES_H_
