#ifndef COLA_DINAMICA_H_INCLUDED
#define COLA_DINAMICA_H_INCLUDED

typedef struct Nodo {
    void *info;
    unsigned tamInfo;
    struct Nodo *sig;
} Nodo;

typedef struct {
    Nodo *pri;
    Nodo *ult;
} Cola;

#endif // COLA_DINAMICA_H_INCLUDED
