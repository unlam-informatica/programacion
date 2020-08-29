#ifndef COLA_ESTATICA_H_INCLUDED
#define COLA_ESTATICA_H_INCLUDED

#define minimo( x , y ) (( x ) <= ( y )? ( x ) : ( y ))

#define TAM_COLA 500

#define TODO_OK 0
#define COLA_LLENA 1
#define COLA_VACIA 2

typedef struct {
    char cola[TAM_COLA];
    unsigned pri, ult, tamDisp;
} ColaEstatica;

void crearColaEstatica(ColaEstatica *cola);

int colaEstaticaLlena(const ColaEstatica *cola, unsigned cantBytes);

int ponerEnColaEstatica(ColaEstatica *cola, const void *d, unsigned cantBytes);

int verPrimeroColaEstatica(const ColaEstatica *cola, void *d, unsigned cantBytes);

int colaEstaticaVacia(const ColaEstatica *cola);

int sacarDeColaEstatica(ColaEstatica *cola, void *d, unsigned cantBytes);

void vaciarColaEstatica(ColaEstatica *cola);

#endif // COLA_ESTATICA_H_INCLUDED
