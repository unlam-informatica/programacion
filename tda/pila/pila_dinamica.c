#include <string.h>
#include <stdlib.h>

#include "pila_dinamica.h"

void crearPilaDinamica(PilaDinamica *p)
{
    *p = NULL;
}

int PilaDinamicaLlena(const PilaDinamica *p, unsigned cantBytes)
{
    Nodo *aux = (Nodo *) malloc (sizeof(Nodo));
    void *info = malloc(cantBytes);

    free(aux);
    free(info);
    return aux == NULL || info == NULL;
}

int ponerEnPilaDinamica(PilaDinamica *p, const void *d, unsigned cantBytes)
{
    Nodo *nue = (Nodo *) malloc(sizeof(Nodo));
    nue->info = malloc(cantBytes);
    if(nue == NULL || nue->info == NULL)
    {
        free(nue->info);
        free(nue);
        return 0;
    }
    memcpy(nue->info, d, cantBytes);
    nue->tamInfo = cantBytes;
    nue->sig = *p;
    *p = nue;
    return 1;
}

int verTopePilaDinamica(const PilaDinamica *p, void *d, unsigned cantBytes)
{
    if(*p == NULL){
        return 0;
    }
    memcpy(d, (*p)->info, minimo(cantBytes, (*p)->tamInfo));
    return 1;
}

int PilaDinamicaVacia(const PilaDinamica *p) {
    return *p == NULL;
}

int sacarDePilaDinamica(PilaDinamica *p, void *d, unsigned cantBytes) {
    Nodo *aux = *p;
    if(aux == NULL){
        return 0;
    }
    *p = aux->sig;
    memcpy(d, aux->info, minimo(cantBytes, aux->tamInfo));
    free(aux->info);
    free(aux);
    return 1;
}

void vaciarPilaDinamica(PilaDinamica *p) {
    while(*p){
        Nodo *aux = *p;
        *p = aux->sig;
        free(aux->info);
        free(aux);
    }
}
