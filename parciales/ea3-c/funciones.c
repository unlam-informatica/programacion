/**//* 35.588.676-RIOS,MarcosAdrian-(01-2964) *//**/


/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//* CUALQUIER INCLUDE DE BIBLIOTECA QUE NECESITE, HÁGALO ACÁ   *//**//**/

#include <string.h>
#include <stdlib.h>

/**//**//* CUALQUIER INCLUDE DE BIBLIOTECA QUE NECESITE, HÁGALO ACÁ   *//**//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
#include "funciones.h"

#define REDONDEAR(a,b) ((((float)a/b)/10) >= 0.5) ? ((int)(((float)a/b)+0.5)):(a/b)

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//* ACÁ DEBE DESARROLLAR LAS FUNCIONES Y PRIMITIVAS PEDIDAS    *//**//**/
/**//**//* ADEMÁS DE CUALQUIER OTRA FUNCIÓN QUE SE REQUIERA           *//**//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* FUNCIONES Y PRIMITIVAS A DESARROLLAR                               *//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* para la información                                                *//**/
tNodo* _obtenerMayor(const tLista *q, int (*comparar)(const void *, const void *));

void mostrarFinal_MIO(const void *d, FILE *fp)
{
    if(d)
    {
        fprintf(fp,
                "%-8s %-*s %-d %2d\n",
                ((const tFinal*)d)->dni,
                sizeof(((const tFinal*)d)->apYNom) - 1, ((const tFinal*)d)->apYNom,
                ((const tFinal*)d)->codMat, ((const tFinal*)d)->calif);
    }
    else
    {
        fprintf(fp,
                "%-*s %-*s %-s\n",
                sizeof(((const tFinal*)d)->dni) - 1,  " D. N. I.",
                sizeof(((const tFinal*)d)->apYNom) - 1, "Apellido(s), Nombre(s)",
                "CodM Cal");
    }
}

int  compararFinal_MIO(const void *d1, const void *d2)
{
    return strcmp(((const tFinal*)d1)->dni, ((const tFinal*)d2)->dni);
}

int  acumularCalif_MIO(void **dest, unsigned *tamDest,
                       const void *orig, unsigned tamOrig)
{
    tFinal **f1 = (tFinal**)dest;
    tFinal *f2 = (tFinal*)orig;

    return (*f1)->calif += f2->calif;
}

void mostrarProm_MIO(const void *d2, int cantCalif, FILE *fp)
{
    fprintf(fp,
            "   --- Rindio %2d final(es) con un promedio de: %2d\n\n",
            cantCalif,
            REDONDEAR(((tFinal*)d2)->calif, cantCalif));
}


/* para el TDA LISTA                                                  */
int  mostrarDeIzqADer_MIO(const tLista *p,
                          void(*mostrar)(const void *, FILE *), FILE *fp)
{
    tNodo *act = *p;
    int cant = 0;

    if(act)
    {
        mostrar(NULL, fp);
        while(act->ant) act = act->ant;

        while(act)
        {
            mostrar(act->info, fp);
            act = act->sig;
            cant++;
        }
    }
    return cant;
}


void ordenarLista_MIO(tLista *p, int (*comparar)(const void *, const void *))
{
    tNodo *ini = *p;
    if(ini)
    {
        int cant = 0;

        // hago que ini apunte al inicio de la lista
        while(ini->ant) ini = ini->ant;

        tNodo *act = ini, *aux = NULL;
        while(ini->sig)
        {
            tNodo *mayor = _obtenerMayor(&ini, comparar);
            if(mayor)
            {
                act = ini;
                while(act)
                {
                    cant++;
                    if(comparar(act->info, mayor->info) == 0)
                    {
                        aux = act;
                        if(ini == aux)
                        {
                            ini = aux->sig;
                        }
                        else
                        {
                            if(aux->ant)
                            {
                                aux->ant->sig = aux->sig;
                            }
                            if(aux->sig)
                            {
                                aux->sig->ant = aux->ant;
                            }
                            if(ini->ant)
                            {
                                ini->ant->sig = aux;
                            }
                            aux->ant = ini->ant;
                            ini->ant = aux;
                            aux->sig = ini;
                        }
                    }
                    act = act->sig;
                }
            }
        }

    }
}

tNodo* _obtenerMayor(const tLista *q, int (*comparar)(const void *, const void *))
{
    // referencio al primer nodo de la lista
    tNodo *act = *q;
    tNodo *guia = NULL;
    tNodo *nodoMax = NULL;
    int max = 0, cant = 0;
    int vueltas = 0;
    while(act->sig)
    {
        cant = 1;
        guia = act->sig;
        while(guia)
        {
            vueltas++;
            if(comparar(act->info, guia->info) == 0)
            {
                cant++;
            }
            guia = guia->sig;
        }
        if(cant > max)
        {
            max = cant;
            nodoMax = act;
        }
        act = act->sig;
    }
    return nodoMax;
}

int vaciarMostrarDetalleYProm_MIO(tLista *p, FILE *fp,
                                  int (*comparar)(const void *, const void *),
                                  int (*acumular)(void **, unsigned *,
                                          const void *, unsigned),
                                  void (*mostrar)(const void *, FILE *),
                                  void (*mostrar2)(const void *, int, FILE *))
{
    tNodo *guia = *p;
    tNodo *comp = guia;
    int total = 0, finales = 0;

    if(guia)
    {
        // apunto al inicio
        while(guia->ant) guia = guia->ant;

        while(guia)
        {
            comp = guia; //nodo a comparar
            mostrar(NULL, fp);
            mostrar(guia->info, fp);
            finales = 1;
            while(guia && guia->sig && comparar(guia->info,guia->sig->info) == 0)
            {
                finales++;
                mostrar(guia->sig->info,fp);
                acumular(&(guia)->sig->info, &guia->sig->tamInfo, guia->info, guia->tamInfo);
                guia=comp->sig;
                free(comp->info);
                free(comp);
                comp = guia;
            }
            mostrar2(comp->info, finales, fp);
            guia=comp->sig;
            free(comp->info);
            free(comp);
            total += finales;
        }
    }
    return total;
}


/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

