#ifndef PilaEstatica_ESTATICA_INCLUDED
#define PilaEstatica_ESTATICA_INCLUDED

#include "../../guia/core/types.h"

#define TAM_PILA 500
#define minimo(X, Y) ((X) <= (Y) ? (X) : (Y))

typedef struct
{
    char pila[TAM_PILA];
    unsigned tope;
} PilaEstatica;

void crearPilaEstatica(PilaEstatica *p);

int pilaEstaticaLlena(const PilaEstatica *p, unsigned cantBytes);

int pilaPilaEstaticaVacia(const PilaEstatica *p);

int verTopePilaEstatica(const PilaEstatica *p, void *d, unsigned cantBytes);

int ponerEnPilaEstatica(PilaEstatica *p, const void *d, unsigned cantBytes);

int sacarDePilaEstatica(PilaEstatica *p, void *d, unsigned cantBytes);

void vaciarPilaEstatica(PilaEstatica *p);

#endif // PilaEstatica_ESTATICA_INCLUDED
