#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

void crearPila(Pila *p);

int pilaLlena(const Pila *p, unsigned cantBytes);

int ponerEnPila(Pila *p, const void *d, unsigned cantBytes);

int verTope(const Pila *p, void *d, unsigned cantBytes);

int pilaVacia(const Pila *p);

int sacarDePila(Pila *p, void *d, unsigned cantBytes);

void vaciarPila(Pila *p);

#endif // PILA_H_INCLUDED
