/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//* NO DEBE HACER NINGUNA MODIFICACIÓN EN ESTE ARCHIVO         *//**//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include <stdio.h>


/**//* para la información                                                *//**/
typedef struct
{
    char    dni[11];
    char    apYNom[31];
    int     codMat,
            calif;
} tFinal;


void mostrarFinal(const void *d, FILE *fp);

int  compararFinal(const void *d1, const void *d2);

int  acumularCalif(void **dest, unsigned *tamDest,
                   const void *orig, unsigned tamOrig);

void mostrarProm(const void *d2, int cantCalif, FILE *fp);


/**//* para el TDA LISTA                                                  *//**/
#define SIN_MEM     0
#define TODO_BIEN   1
#define CLA_DUP     2


typedef struct sNodo
{
    void           *info;
    unsigned        tamInfo;
    struct sNodo   *sig,
                   *ant;
} tNodo;
typedef tNodo *tLista;


int crearYcargarLista(tLista *p);


int  mostrarDeIzqADer(const tLista *p,
                      void(*mostrar)(const void *, FILE *), FILE *fp);

void ordenarLista(tLista *p, int (*comparar)(const void *, const void *));

int  vaciarMostrarDetalleYProm(tLista *p, FILE *fp,
                               int (*comparar)(const void *, const void *),
                               int (*acumular)(void **, unsigned *, const void *, unsigned),
                               void (*mostrar)(const void *, FILE *),
                               void (*mostrar2)(const void *, int, FILE *));

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* para la información                                                *//**/
void mostrarFinal_MIO(const void *d, FILE *fp);

int  compararFinal_MIO(const void *d1, const void *d2);

int  acumularCalif_MIO(void **dest, unsigned *tamDest,
                       const void *orig, unsigned tamOrig);

void mostrarProm_MIO(const void *d2, int cantCalif, FILE *fp);

/**//* para el TDA LISTA                                                  *//**/
int  mostrarDeIzqADer_MIO(const tLista *p,
                          void(*mostrar)(const void *, FILE *), FILE *fp);

void ordenarLista_MIO(tLista *p, int (*comparar)(const void *, const void *));

int  vaciarMostrarDetalleYProm_MIO(tLista *p, FILE *fp,
                                   int (*comparar)(const void *, const void *),
                                   int (*acumular)(void **, unsigned *,
                                                   const void *, unsigned),
                                   void (*mostrar)(const void *, FILE *),
                                   void (*mostrar2)(const void *, int, FILE *));

#endif // FUNCIONES_H_

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

