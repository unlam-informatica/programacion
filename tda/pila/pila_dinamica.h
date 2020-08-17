#ifndef PILA_DINAMICA_H_INCLUDED
#define PILA_DINAMICA_H_INCLUDED

#define minimo(X, Y) ((X) <= (Y) ? (X) : (Y))

typedef struct Nodo {
    void *info;
    unsigned tamInfo;
    struct Nodo *sig;

} Nodo;

typedef Nodo *PilaDinamica;

void crearPilaDinamica(PilaDinamica *p);

int PilaDinamicaLlena(const PilaDinamica *p, unsigned cantBytes);

int ponerEnPilaDinamica(PilaDinamica *p, const void *d, unsigned cantBytes);

int verTope(const PilaDinamica *p, void *d, unsigned cantBytes);

int PilaDinamicaVacia(const PilaDinamica *p);

int sacarDePilaDinamica(PilaDinamica *p, void *d, unsigned cantBytes);

void vaciarPilaDinamica(PilaDinamica *p);

#endif // PILA_DINAMICA_H_INCLUDED
