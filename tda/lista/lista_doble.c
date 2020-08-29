#include <stdlib.h>

#include "lista_doble.h"

void crearListaDoble(ListaDoble *p)
{
    *p = NULL;
}

int vaciarListaDoble(ListaDoble *p)
{
    int cant = 0;
    Nodo *act = *p;

    if(act)
    {
        while(act->ant)
        {
            act = act->ant;
        }
        while(act)
        {
            Nodo *aux = act->sig;
            free(act->info);
            free(act);
            act = aux;
            cant++;
        }
        *p = NULL;
    }
    return cant;
}

int listaDobleVacia(const ListaDoble *p)
{
    return *p == NULL;
}

int listaDobleLlena(const ListaDoble *p, unsigned tamElem)
{
    Nodo *nue = (Nodo *) malloc(sizeof(Nodo));
    void *info = malloc(tamElem);

    free(nue);
    free(info);
    return info = NULL || nue == NULL;
}

int insertarAlFinalListaDoble(const ListaDoble *p, const void *d, unsigned tamElem)
{
    Nodo *act = *p, *nue;

    if(act)
    {
        while(act->sig)
        {
            act = act->sig;
        }
    }
    nue = (Nodo *)(malloc(sizeof(Nodo)));
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
    nue->ant = act;
    if(act)
    {
        act->sig = nue;
    }
    *p = nue;
    return 1;
}

int insertarAlInicioListaDoble(const ListaDoble *p, const void *d, unsigned tamElem)
{
    Nodo *act = *p;

    if(act)
    {
        while(act->ant)
        {
            act = act->ant;
        }
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
    nue->sig = act;
    nue->ant = NULL;
    if(act)
    {
        act->ant = nue;
    }
    *p = nue;
    return 1;
}

int mostrarIzqADerListaDoble(const ListaDoble *p, void (* mostrar)(const void *))
{
    Nodo *act = *p;
    int cant = 0;
    if(act)
    {
        mostrar(NULL);
        while(act->ant)
        {
            act = act->ant;
        }
        while(act)
        {
            mostrar(act->info);
            act = act->sig;
            cant++;
        }
    }
    return cant;
}

int mostrarDerAIzqListaDoble(const ListaDoble *p, void (* mostrar)(const void *))
{
    Nodo *act = *p;
    int cant = 0;
    if(act)
    {
        mostrar(NULL);
        while(act->sig)
        {
            act = act->sig;
        }
        while(act)
        {
            mostrar(act->info);
            act = act->ant;
            cant++;
        }
    }
    return cant;
}

int insertarEnOrdenListaDoble(ListaDoble *p,
                              const void *d,
                              unsigned tamElem,
                              int (*comparar)(const void *, const void *),
                              int (*acumular)(void **, unsigned *, const void *, unsigned))
{
    Nodo *act = *p;
    Nodo *ant, *nue, *sig;
    if(act == NULL)
    {
        ant = NULL;
        sig = NULL;
    }
    else
    {
        while(act->sig && comparar(act->info, d) < 0)
        {
            act = act->sig;
        }
        while(act->ant && comparar(act->info, d) > 0)
        {
            act = act->ant;
        }
        int aux = comparar(act->info, d);
        if(aux == 0)
        {
            *p = act;
            if(acumular)
            {
                if(acumular(&act->info, &act->tamInfo, d, tamElem) == 0)
                {
                    return SIN_MEM;
                }
            }
            return CLA_DUP;
        }
        if(aux < 0)
        {
            ant = act;
            sig = act->sig;
        }
        else
        {
            ant = act->ant;
            sig = act;
        }
    }
    nue = (Nodo *) malloc(sizeof(Nodo));
    if(nue == NULL)
    {
        return 0;
    }
    nue->info = malloc(tamElem);
    if(nue->info == NULL)
    {
        free(nue);
        return SIN_MEM;
    }
    memcpy(nue->info, d, tamElem);
    nue->tamInfo = tamElem;
    nue->sig = sig;
    nue->ant = ant;
    if(sig)
    {
        sig->ant = nue;
    }
    if(ant)
    {
        ant->sig = nue;
    }
    *p = nue;
    return TODO_BIEN;
}

void ordenarListaDoble(ListaDoble *p, int (*comparar)(const void *, const void *))
{

}

int eliminarPorClaveListaDoble(ListaDoble *p,
                               void *d,
                               unsigned tamElem,
                               int (*comparar)(const void *, const void *))
{
    Nodo *act = *p;
    int aux;

    if(act = NULL)
    {
        return 0;
    }
    while(act->sig && comparar(act->info, d) < 0)
    {
        act = act->sig;
    }
    while(act->ant && comparar(act->info, d) > 0)
    {
        act = act->ant;
    }
    aux = comparar(act->info, d);

    if(aux == 0)
    {
        Nodo *ant = act->ant;
        Nodo *sig = act->sig;

        if(ant)
        {
            ant->sig = sig;
        }
        if(sig)
        {
            sig->ant = ant;
            *p = sig;
        }
        else
        {
            *p = ant;
        }
        memcpy(d, act->info, tamElem);
        free(act->info);
        free(act);
        return 1;
    }
    return 0;
}
