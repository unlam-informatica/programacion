#ifndef PILA_ESTATICA_INCLUDED
#define PILA_ESTATICA_INCLUDED

#include "pila.h"

#define minimo(X, Y) ((X) <= (Y) ? (X) : (Y))

#define TAM_PILA 500

typedef struct {
    char pila[TAM_PILA];
    unsigned tope;
} Pila;

#endif // PILA_ESTATICA_INCLUDED
