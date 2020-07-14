/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//* NO DEBE HACER NINGUNA MODIFICACIÓN EN ESTE ARCHIVO         *//**//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include <stdio.h>


/**//* para la información                                                *//**/
typedef struct
{
    char    ctaCte[16];
    double  saldo;
} tMovi;

void mostrarMovim(const void *d, FILE *fp);

int compararMovim(const void *d1, const void *d2);

int esCtaCte002(const void *d);

int acumularMoviSaldo(void **dest, unsigned *tamDest,
                      const void *ori, unsigned tamOri);

void mostrarTotal(const void *d, FILE *fp);

/**//* para el TDA LISTA                                                  *//**/
typedef struct tNodo
{
    void           *info;
    unsigned        tamInfo;
    struct tNodo   *sig;
} tNodo,  *tLista;


int crearYcargarLista(tLista *p);

int mostrarLista(const tLista *p,
                 void (*mostrar)(const void *, FILE *), FILE *fp);


void ordenarLista(tLista *p, int (*comparar)(const void *, const void *));

int eliminarMostrarYMostrarSubTot(tLista *p, FILE *fpPant,
                                  int comparar(const void *, const void *),
                                  int esBuscado(const void *d),
                                  int acumular(void **, unsigned *,
                                               const void *, unsigned),
                                  void mostrar(const void *, FILE *),
                                  void mostrar2(const void *, FILE *));

int  vaciarListaYMostrar(tLista *p,
                         void (*mostrar)(const void *, FILE *), FILE *fp);


/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* para la información                                                *//**/

void mostrarMovim_MIO(const void *d, FILE *fp);

int compararMovim_MIO(const void *d1, const void *d2);

int esCtaCte002_MIO(const void *d);

int acumularMoviSaldo_MIO(void **dest, unsigned *tamDest,
                          const void *ori, unsigned tamOri);

void mostrarTotal_MIO(const void *d, FILE *fp);

/**//* para el TDA LISTA                                                  *//**/

int mostrarLista_MIO(const tLista *p,
                     void (*mostrar)(const void *, FILE *), FILE *fp);


void ordenarLista_MIO(tLista *p, int (*comparar)(const void *, const void *));

int eliminarMostrarYMostrarSubTot_MIO(tLista *p, FILE *fpPant,
                                      int comparar(const void *, const void *),
                                      int comparar2(const void *d),
                                      int acumular(void **, unsigned *,
                                                   const void *, unsigned),
                                      void mostrar(const void *, FILE *),
                                      void mostrar2(const void *, FILE *));

int  vaciarListaYMostrar_MIO(tLista *p,
                             void (*mostrar)(const void *, FILE *), FILE *fp);

#endif // FUNCIONES_H_

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

