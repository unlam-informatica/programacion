/**//* 35.588.676-RIOS,MarcosAdrian-(01-2964) *//**/


/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//* CUALQUIER INCLUDE DE BIBLIOTECA QUE NECESITE, HÁGALO ACÁ   *//**//**/

#include "stdlib.h"

/**//**//* CUALQUIER INCLUDE DE BIBLIOTECA QUE NECESITE, HÁGALO ACÁ   *//**//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/


#include "funciones.h"


/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//* ACÁ DEBE DESARROLLAR LAS FUNCIONES Y PRIMITIVAS PEDIDAS    *//**//**/
/**//**//* ADEMÁS DE CUALQUIER OTRA FUNCI�N QUE SE REQUIERA           *//**//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* FUNCIONES Y PRIMITIVAS A DESARROLLAR                               *//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* para la información                                                *//**/

void mostrarFinal_MIO(const void *d, FILE *fp)
{
    if(d)
    {
        fprintf(fp,
                "%-8ld %-*s %-d  %d\n",
                ((const tFinal*)d)->DNI,
                sizeof(((const tFinal*)d)->apYNom) - 1, ((const tFinal*)d)->apYNom,
                ((const tFinal*)d)->codMat, ((const tFinal*)d)->calif);
    }
    else
    {
        fprintf(fp,
                "%-*s %-*s %-s\n",
                sizeof(((const tFinal*)d)->DNI) - 1,  "D. N. I.",
                sizeof(((const tFinal*)d)->apYNom) - 1, "Apellido(s), Nombre(s)",
                "Mat.Cali");
    }
}

int compararFinal_MIO(const void *d1, const void *d2)
{
    return ((const tFinal*)d1)->DNI - ((const tFinal*)d2)->DNI;
}

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* para el TDA LISTA                                                  *//**/

int mostrarLista_MIO(const tLista *p,
                     void (*mostrar)(const void *, FILE *), FILE *fp)
{
    int cant = 0;
    if(p != NULL && fp != NULL && mostrar != NULL && *p != NULL)
    {
        mostrar(NULL, fp);
        do
        {
            mostrar((*p)->info, fp);
            p = &(*p)->sig;
            cant++;
        }
        while(*p != NULL);
    }
    return cant;
}

int eliminarYMostrarUnicos_MIO(tLista *p, FILE *fpPant,
                               int comparar(const void *, const void *),
                               void mostrar(const void *, FILE *))
{
    tLista *cp = p;
    tLista *ini = p;
    tNodo *aux;
    int cant = 0;
    int dup = 0;
    mostrar(NULL, fpPant);
    while(*ini)
    {
        p=cp;
        while(*p && dup==0)
        {
            if(*ini!=*p && comparar((*ini)->info,(*p)->info)==0)
                dup=1;
            p=&(*p)->sig;
        }
        if(dup==0)
        {
            mostrar((*ini)->info,fpPant);
            aux=*ini;
            *ini=aux->sig;
            free(aux->info);
            free(aux);
            cant++;
        }
        else
        {
            dup=0;
            ini=&(*ini)->sig;
        }
    }
    return cant;
}


int eliminarYMostrarRepetidos_MIO(tLista *p, FILE *fpPant,
                                  int comparar(const void *, const void *),
                                  void mostrar(const void *, FILE *))
{
    int cant = 0;
    if(*p && (*p)->sig)
    {
        int esPrimero = 1;
        int huboDuplicado = 0;
        tNodo *aux;
        tLista *cp;

        mostrar(NULL, fpPant);
        while(*p && (*p)->sig)
        {
            cp = &(*p)->sig;
            while(*cp && (*cp)->sig)
            {
                if(comparar((*p)->info, (*cp)->sig->info) == 0)
                {
                    cant++;
                    huboDuplicado = 1;
                    if(esPrimero)
                    {
                        mostrar((*p)->info, fpPant);
                        esPrimero = 0;
                    }
                    aux = (*cp)->sig;
                    mostrar(aux->info, fpPant);
                    (*cp)->sig = aux->sig;
                    free(aux->info);
                    free(aux);
                }
                else
                {
                    cp = &(*cp)->sig;
                }
            }
            if(huboDuplicado)
            {
                cant++;
                aux = *p;
                *p= aux->sig;
                free(aux->info);
                free(aux);
                esPrimero = 1;
                huboDuplicado = 0;
            }
            else
            {
                p = &(*p)->sig;
            }
        }
    }
    return cant;
}
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

