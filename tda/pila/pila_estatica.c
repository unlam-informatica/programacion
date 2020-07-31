#include <string.h>

#include "pila_estatica.h"

void crearPila(Pila *p)
{
    p->tope = TAM_PILA;
}

int pilaLlena(const Pila *p, unsigned cantBytes)
{
    return p->tope < cantBytes + sizeof(unsigned);
}

// Cada vez que pongo un valor en la pila, disminuyo los bytes disponibles en tope
int ponerEnPila(Pila *p, const void *d, unsigned cantBytes)
{
    if(p->tope < cantBytes + sizeof(unsigned))
    {
        return 0;
    }
    p->tope -= cantBytes;
    memcpy(p->pila + p->tope, d, cantBytes);
    p->tope -= sizeof(unsigned);
    memcpy(p->pila + p->tope, &cantBytes, sizeof(unsigned));
    return 1;
}

int verTope(const Pila *p, void *d, unsigned cantBytes)
{
    unsigned tamInfo;

    if(p->tope == TAM_PILA)
    {
        return 0;
    }
    memcpy(&tamInfo, p->pila + p->tope, sizeof(unsigned));
    memcpy(d, p->pila + p->tope + sizeof(unsigned), minimo(cantBytes, tamInfo));
    return 1;
}

int pilaVacia(const Pila *p)
{
    return p->tope == TAM_PILA;
}

int sacarDePila(Pila *p, void *d, unsigned cantBytes) {
    unsigned tamInfo;

    if(t->tope == TAM_PILA){
        return 0;
    }
    memcpy(&tamInfo, p->pila + p->tope, sizeof(unsigned));
    p->tope += sizeof(unsigned);
    memcpy(d, p->pila + p->tope, minimo(cantBytes, tamInfo));
    p->tope += tamInfo;
    return 1;
}

void vaciarPila(Pila *p){
    p->tope = TAM_PILA;
}
