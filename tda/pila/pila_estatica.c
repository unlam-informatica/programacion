#include <string.h>

#include "pila_estatica.h"

void crearPilaEstatica(PilaEstatica *p)
{
    p->tope = 0;
}

int pilaEstaticaVacia(const PilaEstatica *p)
{
    return p->tope == 0;
}

void vaciarPilaEstatica(PilaEstatica *p)
{
    p->tope = 0;
}

int pilaEstaticaLlena(const PilaEstatica *p, unsigned tamElem)
{
    return p->tope + tamElem + sizeof(unsigned) > TAM_PILA;
}

int ponerEnPilaEstatica(PilaEstatica *p, const void *d, unsigned tamElem)
{
    if(p->tope + tamElem + sizeof(unsigned) > TAM_PILA)
    {
        return FALSO;
    }

    // incremento por el tamaño del dato
    p->tope += tamElem;
    memcpy(p->pila + p->tope, d, tamElem);

    // incremento por el tamaño de la variable que almacena el tamaño del dato
    p->tope += sizeof(unsigned);
    memcpy(p->pila + p->tope, &tamElem, sizeof(unsigned));

    return VERDADERO;
}

int sacarDePilaEstatica(PilaEstatica *p, void *d, unsigned tamElem)
{
    if(p->tope == 0)
    {
        return FALSO;
    }

    // retrocedo y leo el tamaño
    p->tope -= sizeof(unsigned);
    unsigned tamElemReal = *(unsigned *)(p->pila + p->tope);

    // retrocedo el tamaño
    p->tope -= tamElemReal;
    memcpy(d, p->pila + p->tope, minimo(tamElem, tamElemReal));

    return VERDADERO;
}

int verTopePilaEstatica(const PilaEstatica *p, void *d, unsigned tamElem)
{
    if(p->tope == 0)
    {
        return FALSO;
    }

    // utilizo tome temporal porque la funcion no modifica la pila
    unsigned topeTmp = p->tope;

    topeTmp -= sizeof(unsigned);
    unsigned tamElemReal = *(unsigned *)(p->pila + topeTmp);

    topeTmp -= tamElemReal;
    memcpy(d, p->pila + topeTmp, minimo(tamElem, tamElemReal));
    return VERDADERO;
}
