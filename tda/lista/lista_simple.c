#include <stdlib.h>
#include <string.h>

#include "lista_simple.h"

void crearListaSimple(ListaSimple *p)
{
    *p = NULL;
}

int listaSimpleVacia(const ListaSimple *p)
{
    return *p == NULL;
}

void vaciarLista(ListaSimple *p)
{
    while(*p)
    {
        Nodo *aux = *p;
        *p = aux->sig;
        free(aux->info);
        free(aux);
    }
}

int listaSimpleLlena(const ListaSimple *p, unsigned tamElem)
{
    Nodo *nodo = (Nodo *) malloc(sizeof(Nodo));
    void *info = malloc(tamElem);

    free(nodo);
    free(info);

    return nodo == NULL || info == NULL;
}

int ponerAlInicioListaSimple(ListaSimple *p, const void *d, unsigned tamElem)
{
    Nodo *nue = (Nodo *) malloc(sizeof(Nodo));
    if(nue == NULL)
    {
        return 0;
    }
    nue->info = malloc(tamElem);
    if(nue->info == NULL)
    {
        free(nue);
        return 0;
    }
    memcpy(nue->info, d, tamElem);
    nue->tamInfo = tamElem;
    nue->sig = *p;
    *p = nue;
    return 1;
}

int ponerAlFinalListaSimple(ListaSimple *p, const void *d, unsigned tamElem)
{
    while(*p)
    {
        p = &(*p)->sig;
    }
    Nodo *nue = (Nodo *) malloc(sizeof(Nodo));
    if(nue == NULL)
    {
        return 0;
    }
    nue->info = malloc(tamElem);
    if(nue->info == NULL)
    {
        free(nue);
        return 0;
    }
    memcpy(nue->info, d, tamElem);
    nue->tamInfo = tamElem;
    nue->sig = NULL;
    *p = nue;
    return 1;
}

int verPrimeroListaSimple(const ListaSimple *p, void *d, unsigned tamElem)
{
    if(*p == NULL)
    {
        return 0;
    }
    memcpy(d, (*p)->info, minimo(tamElem, (*p)->tamInfo));
    return 1;
}

int sacarPrimeroListaLlena(ListaSimple *p, void *d, unsigned tamElem)
{
    Nodo *aux = *p;
    if(aux == NULL)
    {
        return 0;
    }
    *p = aux->sig;
    memcpy(d, aux->info, minimo(tamElem, aux->tamInfo));
    free(aux->info);
    free(aux);
    return 1;
}

int verUltimoListaSimple(const ListaSimple *p, void *d, unsigned tamElem){
    if(*p == NULL){
        return 0;
    }
    while((*p)->sig){
        p = &(*p)->sig;
    }
    memcpy(d, (*p)->info, minimo(tamElem, (*p)->tamInfo));
    return 1;
}
