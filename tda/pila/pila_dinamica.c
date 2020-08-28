#include <string.h>
#include <stdlib.h>

#include "../../guia/core/types.h"
#include "pila_dinamica.h"

void crearPilaDinamica(PilaDinamica *p)
{
    *p = NULL;
}

int PilaDinamicaVacia(const PilaDinamica *p)
{
    return *p == NULL;
}

void vaciarPilaDinamica(PilaDinamica *p)
{
    while(*p)
    {
        Nodo *aux = *p;
        *p = aux->sig;
        free(aux->info);
        free(aux);
    }
}

int pilaDinamicaLlena(const PilaDinamica *p, unsigned tamElem)
{
    Nodo *aux = (Nodo *) malloc (sizeof(Nodo));
    void *info = malloc(tamElem);

    free(aux);
    free(info);
    return aux == NULL || info == NULL;
}

int ponerEnPilaDinamica(PilaDinamica *p, const void *d, unsigned tamElem)
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

int sacarDePilaDinamica(PilaDinamica *p, void *d, unsigned tamElem)
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

int verTopePilaDinamica(const PilaDinamica *p, void *d, unsigned tamElem)
{
    if(*p == NULL)
    {
        return FALSO;
    }

    memcpy(d, (*p)->info, minimo(tamElem, (*p)->tamInfo));
    return VERDADERO;
}
