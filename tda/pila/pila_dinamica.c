#include <string.h>
#include <stdlib.h>

#include "../../guia/core/types.h"
#include "pila_dinamica.h"

void crearPila(Pila *p)
{
    *p = NULL;
}

int pilaVacia(const Pila *p)
{
    return *p == NULL;
}

void vaciarPila(Pila *p)
{
    while(*p)
    {
        Nodo *aux = *p;
        *p = aux->sig;
        free(aux->info);
        free(aux);
    }
}

int pilaLlena(const Pila *p, unsigned tamElem)
{
    Nodo *aux = (Nodo *) malloc (sizeof(Nodo));
    void *info = malloc(tamElem);

    free(aux);
    free(info);
    return aux == NULL || info == NULL;
}

int ponerEnPila(Pila *p, const void *d, unsigned tamElem)
{
    Nodo *nue = (Nodo *) malloc(sizeof(Nodo));
    nue->info = malloc(tamElem);
    if(nue == NULL || nue->info == NULL)
    {
        free(nue->info);
        free(nue);
        return FALSO;
    }
    memcpy(nue->info, d, tamElem);
    nue->tamInfo = tamElem;
    nue->sig = *p;
    *p = nue;
    return VERDADERO;
}

int sacarDePila(Pila *p, void *d, unsigned tamElem)
{
    if(*p == NULL)
    {
        return FALSO;
    }

    Nodo *aux = *p;
    *p = aux->sig;
    memcpy(d, aux->info, minimo(tamElem, aux->tamInfo));

    free(aux->info);
    free(aux);

    return VERDADERO;
}

int verTopePila(const Pila *p, void *d, unsigned tamElem)
{
    if(*p == NULL)
    {
        return FALSO;
    }

    memcpy(d, (*p)->info, minimo(tamElem, (*p)->tamInfo));
    return VERDADERO;
}
