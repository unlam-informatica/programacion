/**//* 35.588.676-RIOS,MarcosAdrian-(01-2964) *//**/


/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//* CUALQUIER INCLUDE DE BIBLIOTECA QUE NECESITE, H�GALO AC�   *//**//**/
#include <string.h>
#include <stdlib.h>

/**//**//* CUALQUIER INCLUDE DE BIBLIOTECA QUE NECESITE, H�GALO AC�   *//**//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
#include "funciones.h"
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//* AC� DEBE DESARROLLAR LAS FUNCIONES Y PRIMITIVAS PEDIDAS    *//**//**/
/**//**//* ADEM�S DE CUALQUIER OTRA FUNCI�N QUE SE REQUIERA           *//**//**/


/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* FUNCIONES Y PRIMITIVAS A DESARROLLAR                               *//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* para la informaci�n                                                *//**/

void mostrarMovim_MIO(const void *d, FILE *fp)
{
    const tMovi *mov = d;
    if(mov)
        fprintf(fp,
                "%-*s %*.02f\n",
                (int)sizeof(mov->ctaCte), mov->ctaCte,
                (int)sizeof(mov->saldo), mov->saldo);
    else
        fprintf(fp,
                "%-*s %*s\n",
                (int)sizeof(mov->ctaCte), "Nro Cuenta Banc",
                (int)sizeof(mov->saldo), "Importe");
}

int compararMovim_MIO(const void *d1, const void *d2)
{
    return strcmp(((tMovi *)d1)->ctaCte, ((tMovi *)d2)->ctaCte);
}


int esCtaCte002_MIO(const void *d)
{
    const char *p = "002";
    d = (((const tMovi*)d)->ctaCte + 12);
    while(*p && *p == *(const char *)d)
    {
        p++;
        (const char *)d++;
    }

    return !(*p - *(const char *)d);
}


int acumularMoviSaldo_MIO(void **dest, unsigned *tamDest,
                          const void *ori, unsigned tamOri)
{
    ((tMovi*)*dest)->saldo += ((const tMovi*)ori)->saldo;
    return 1;
}


void mostrarTotal_MIO(const void *d, FILE *fp)
{
    fprintf(fp," Total cliente: %9.2lf\n\n",((const tMovi *)d)->saldo);
}


/**//* para el TDA LISTA                                                  *//**/
int mostrarLista_MIO(const tLista *p,
                     void (*mostrar)(const void *, FILE *),
                     FILE *fp)
{
    int cant = 0;
    mostrar(NULL, fp);
    while(*p)
    {
        mostrar((*p)->info, fp);
        p = &(*p)->sig;
        cant++;
    }
    return cant;
}

// tLista *p = direccion de un puntero a nodo
void ordenarLista_MIO(tLista *p, int (*comparar)(const void *, const void *))
{
    // subLista de busqueda
    tLista *subLista, *posMenor;
    tNodo  *nodoMenor;

    while(*p && (*p)->sig)
    {
        subLista = &(*p)->sig;
        posMenor = p;

        while(*subLista)
        {
            if(comparar((*subLista)->info, (*posMenor)->info) < 0)
            {
                posMenor = subLista;
            }
            subLista = &(*subLista)->sig;
        }

        if(*posMenor != *p)
        {
            nodoMenor = *posMenor;
            *posMenor = nodoMenor->sig;
            nodoMenor->sig = *p;
            *p = nodoMenor;
        }

        p = &(*p)->sig;
    }

    // tNodo* *menor;
    // tLista *subLista, *posMenor;

    // while(*p && (*p)->sig)
    // {
    //     subLista = &(*p)->sig;
    //     tNodo *minAct = q;
    //     tNodo *preMin = NULL;
    //     while(*subLista)
    //     {
    //         printf("Q actual: %s\n", ((tMovi *)q->info)->ctaCte);
    //         if(comparar(q->sig->info, minAct->info) < 0)
    //         {
    //             preMin = q;
    //             minAct = q->sig;
    //             if(primero)
    //             {
    //                 inicio = &(q->sig);
    //                 primero = 0;
    //             }
    //         }
    //         q = q->sig;
    //     }
    //     puts("\n");
    //     if(preMin)
    //     {
    //         preMin->sig = minAct->sig;
    //         minAct->sig = *p;
    //     }
    //     p = &(*p)->sig;
    // }
    // *p = *inicio;
}


//int eliminarMostrarYMostrarSubTot_MIO(tLista *p, FILE *fpPant,
//                                      int comparar(const void *, const void *),
//                                      int comparar2(const void *d),
//                                      int acumular(void **, unsigned *,
//                                                   const void *, unsigned),
//                                      void mostrar(const void *, FILE *),
//                                      void mostrar2(const void *, FILE *))
//{
//
//}
//
int  vaciarListaYMostrar_MIO(tLista *p,
                             void (*mostrar)(const void *, FILE *), FILE *fp)
{
    int cant = 0;
    while(*p)
    {
        tNodo *aux = *p;
        cant++;
        *p = aux->sig;
        if(mostrar && fp)
        {
            mostrar(aux->info, fp);
        }
        free(aux->info);
        free(aux);
    }
    return cant;
}
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

