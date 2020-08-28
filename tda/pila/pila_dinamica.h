#ifndef PILA_DINAMICA_H_INCLUDED
#define PILA_DINAMICA_H_INCLUDED

#define minimo(X, Y) ((X) <= (Y) ? (X) : (Y))

typedef struct Nodo {
    void *info;
    unsigned tamInfo;
    struct Nodo *sig;

} Nodo;

typedef Nodo* Pila;

void crearPila(Pila *p);

void vaciarPila(Pila *p);

int pilaVacia(const Pila *p);

int pilaLlena(const Pila *p, unsigned cantBytes);

int ponerEnPila(Pila *p, const void *d, unsigned cantBytes);

int sacarDePila(Pila *p, void *d, unsigned cantBytes);

int verTope(const Pila *p, void *d, unsigned cantBytes);

#endif // PILA_DINAMICA_H_INCLUDED
