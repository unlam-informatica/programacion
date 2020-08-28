#ifndef LISTA_SIMPLE_H_INCLUDED
#define LISTA_SIMPLE_H_INCLUDED

#define minimo(X, Y) ((X) <= (Y) ? (X) : (Y))

typedef struct sNodo {
    void *info;
    unsigned tamInfo;
    struct sNodo *sig;
} Nodo;

typedef Nodo* ListaSimple;


void crearListaSimple(ListaSimple *p);

int listaSimpleVacia(const ListaSimple *p);

void vaciarLista(ListaSimple *p);

int listaSimpleLlena(const ListaSimple *p, unsigned tamElem);

int ponerAlInicioListaSimple(ListaSimple *p, const void *d, unsigned tamElem);

int ponerAlFinalListaSimple(ListaSimple *p, const void *d, unsigned tamElem);

int verPrimeroListaSimple(const ListaSimple *p, void *d, unsigned tamElem);

int sacarPrimeroListaLlena(ListaSimple *p, void *d, unsigned tamElem);

int verUltimoListaSimple(const ListaSimple *p, void *d, unsigned tamElem);

#endif // LISTA_SIMPLE_H_INCLUDED
