#ifndef LISTA_SIMPLE_H_INCLUDED
#define LISTA_SIMPLE_H_INCLUDED

typedef struct sNodo {
    void *info;
    unsigned tamInfo;
    struct sNodo *sig;
} Nodo;

typedef Nodo* Lista;

void crearLista(Lista *p);

#endif // LISTA_SIMPLE_H_INCLUDED
