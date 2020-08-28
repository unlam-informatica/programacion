#ifndef PilaDinamica_DINAMICA_H_INCLUDED
#define PilaDinamica_DINAMICA_H_INCLUDED

#define minimo(X, Y) ((X) <= (Y) ? (X) : (Y))

typedef struct Nodo {
    void *info;
    unsigned tamInfo;
    struct Nodo *sig;

} Nodo;

typedef Nodo* PilaDinamica;

void crearPilaDinamica(PilaDinamica *p);

void vaciarPilaDinamica(PilaDinamica *p);

int pilaDinamicaVacia(const PilaDinamica *p);

int pilaDinamicaLlena(const PilaDinamica *p, unsigned cantBytes);

int ponerEnPilaDinamica(PilaDinamica *p, const void *d, unsigned cantBytes);

int sacarDePilaDinamica(PilaDinamica *p, void *d, unsigned cantBytes);

int verTopePilaDinamica(const PilaDinamica *p, void *d, unsigned cantBytes);

#endif // PilaDinamica_DINAMICA_H_INCLUDED
