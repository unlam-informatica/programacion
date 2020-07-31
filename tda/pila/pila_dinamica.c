#include "pila_dinamica.h"

void crearPila(Pila *p)
{
    *p = NULL;
}

int pilaLlena(const Pila *p, unsigned cantBytes)
{
    Nodo *aux = (Nodo *) malloc (sizeof(Nodo));
    void *info = malloc(cantBytes);

    free(aux);
    free(info);
    return aux = NULL || info == NULL;
}

int ponerEnPila(Pila *p, const void *d, unsigned cantBytes)
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

int verTope(const Pila *p, void *d, unsigned cantBytes)
{
    if(*p == NULL){
        return 0;
    }
    memcpy(d, (*p)->info, minimo(cantBytes, (*p)->tamInfo));
    return 1;
}

int pilaVacia(const Pila *p) {
    return *p == NULL;
}

int sacarDePila(Pila *p, void *d, unsigned cantBytes) {
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

void vaciarPila(Pila *p) {
    while(*p){
        Nodo *aux = *p;
        *p = aux->sig;
        free(aux->info);
        free(aux);
    }
}
