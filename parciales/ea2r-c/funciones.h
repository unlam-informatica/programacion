/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//* NO DEBE HACER NINGUNA MODIFICACIÓN EN ESTE ARCHIVO         *//**//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

// se ha hecho lo siguiente por los argumentos FILE * de las funciones
#include <stdio.h>


/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* para la información                                                *//**/
typedef struct
{
    long    DNI;
    char    apYNom[36];
    int     codMat,
            calif;
} tFinal;


void mostrarFinal(const void *d, FILE *fp);


int  compararFinal(const void *d1, const void *d2);


/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
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


int eliminarYMostrarUnicos(tLista *p, FILE *fpPant,
                           int comparar(const void *, const void *),
                           void mostrar(const void *, FILE *));


int eliminarYMostrarRepetidos(tLista *p, FILE *fpPant,
                              int comparar(const void *, const void *),
                              void mostrar(const void *, FILE *));


/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* para la información                                                *//**/
void mostrarFinal_MIO(const void *d, FILE *fp);


int  compararFinal_MIO(const void *d1, const void *d2);


/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* para el TDA LISTA                                                  *//**/
int mostrarLista_MIO(const tLista *p,
                     void (*mostrar)(const void *, FILE *), FILE *fp);


int eliminarYMostrarUnicos_MIO(tLista *p, FILE *fpPant,
                               int comparar(const void *, const void *),
                               void mostrar(const void *, FILE *));


int eliminarYMostrarRepetidos_MIO(tLista *p, FILE *fpPant,
                                  int comparar(const void *, const void *),
                                  void mostrar(const void *, FILE *));



#endif // FUNCIONES_H_

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

