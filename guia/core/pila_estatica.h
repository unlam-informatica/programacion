#ifndef PILA_ESTATICA_H_INCLUDED
#define PILA_ESTATICA_H_INCLUDED

#include <string.h>

#define minimo( X , Y ) ( ( X ) <= ( Y ) ? ( X ) : ( Y ) )

#define TAM_PILA 1024 * 5

typedef struct {
    char pila[TAM_PILA];
    unsigned tope;
} PilaEstatica;

void crear_pila(PilaEstatica *p);

int pila_llena(const PilaEstatica *p, unsigned cant_bytes);

int poner_en_pila(PilaEstatica *p, const void *d, unsigned cant_bytes);

int ver_tope(const PilaEstatica *p, void *d, unsigned cant_bytes);

int pila_vacia(const PilaEstatica *p);

int sacar_de_pila(PilaEstatica *p, void *d, unsigned cant_bytes);

void vaciar_pila(PilaEstatica *p);

#endif // PILA_ESTATICA_H_INCLUDED
