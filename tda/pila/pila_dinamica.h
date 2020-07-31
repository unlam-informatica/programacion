#ifndef PILA_DINAMICA_H_INCLUDED
#define PILA_DINAMICA_H_INCLUDED

#include "pila.h"

typedef struct Nodo {
    void *info;
    unsigned tamInfo;
    struct Nodo *sig;
} Nodo;

typedef Nodo *Pila;

#endif // PILA_DINAMICA_H_INCLUDED
