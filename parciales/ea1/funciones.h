#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

int  contarOcurrencias1(const char *cad, const char *sub);

int  contarOcurrencias2(const char *cad, const char *sub);

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

#define FILAS       15
#define COLUM       FILAS

int  cargarMatConsec(int m[][COLUM], int filas, int colum);

int  mostrarMat(int m[][COLUM], int filas, int colum);

void rotarMat180(int m[][COLUM], int filas, int colum);

int  mostrarMatTriangDerInf(int m[][COLUM], int filas, int colum);

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
void inhibirArchivo(const char *nomArch);
void habilitarArchivo(const char *nomArch);

#define ARCH_ENT    "datos.txt"
#define ARCH_SAL    "nuevo.txt"

int  crearArchivo(const char *nomArch);

void mostrarArchivo(const char *nomArch);

#define ERROR_ARCH_ENT      -1
#define ERROR_ARCH_SAL      -2

int  ordenarArchivo(const char *archEnt, const char *archSal);

/* --------------------------------o---x---o--------------------------------
 *          para la pila con asignación ESTÁTICA de memoria
 *          ***declare y desarrolle sólo las que necesite***
 * --------------------------------o---x---o-------------------------------- */
#define     TAM_PILA        50000

typedef struct
{
    char        pila[TAM_PILA];
    unsigned    tope;
} tPila;

void crearPila(tPila *p);
int  pilaLlena(const tPila *p, unsigned cantBytes);
int  ponerEnPila(tPila *p, const void *d, unsigned cantBytes);
int  verTope(const tPila *p, void *d, unsigned cantBytes);
int  pilaVacia(const tPila *p);
int  sacarDePila(tPila *p, void *d, unsigned cantBytes);
void vaciarPila(tPila *p);


/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* FUNCIONES A DESARROLLAR                                            *//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

int contarOcurrencias1_MIO(const char *cad, const char *sub);

int contarOcurrencias2_MIO(const char *cad, const char *sub);


void rotarMat180_MIO(int m[][COLUM], int filas, int colum);

int  mostrarMatTriangDerInf_MIO(int m[][COLUM], int filas, int colum);


int  ordenarArchivo_MIO(const char *archEnt, const char *archSal);


void crearPila_MIO(tPila *p);

int  pilaLlena_MIO(const tPila *p, unsigned cantBytes);

int  ponerEnPila_MIO(tPila *p, const void *d, unsigned cantBytes);

int  verTope_MIO(const tPila *p, void *d, unsigned cantBytes);

int  pilaVacia_MIO(const tPila *p);

int  sacarDePila_MIO(tPila *p, void *d, unsigned cantBytes);

void vaciarPila_MIO(tPila *p);


/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/



#endif // FUNCIONES_H_
