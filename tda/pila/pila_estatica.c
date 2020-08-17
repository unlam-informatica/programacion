#include <string.h>

#include "pila_estatica.h"

void crearPila(PilaEstatica *p)
{
    p->tope = TAM_PILA;
}

int pilaLlena(const PilaEstatica *p, unsigned cantBytes)
{
    return p->tope < cantBytes + sizeof(unsigned);
}

// Cada vez que pongo un valor en la pila, disminuyo los bytes disponibles en tope
int ponerEnPila(PilaEstatica *p, const void *d, unsigned cantBytes)
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

int verTope(const PilaEstatica *p, void *d, unsigned cantBytes)
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

int pilaVacia(const PilaEstatica *p)
{
    return p->tope == TAM_PILA;
}

int sacarDePila(PilaEstatica *p, void *d, unsigned cantBytes) {
    unsigned tamInfo;

    if(p->tope == TAM_PILA) {
        return 0;
    }
    memcpy(&tamInfo, p->pila + p->tope, sizeof(unsigned));
    p->tope += sizeof(unsigned);
    memcpy(d, p->pila + p->tope, minimo(cantBytes, tamInfo));
    p->tope += tamInfo;
    return 1;
}

void vaciarPila(PilaEstatica *p){
    p->tope = TAM_PILA;
}
