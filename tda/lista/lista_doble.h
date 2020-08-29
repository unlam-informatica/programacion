#ifndef LISTA_DOBLE_H_INCLUDED
#define LISTA_DOBLE_H_INCLUDED

#define SIN_MEM 0
#define TODO_BIEN 1
#define CLA_DUP 2

typedef struct sNodo {
    void *info;
    unsigned tamInfo;
    struct sNodo *ant, *sig;
} Nodo;

typedef Nodo* ListaDoble;

void crearListaDoble(ListaDoble *p);

int vaciarListaDoble(ListaDoble *p);

int listaDobleVacia(const ListaDoble *p);

int listaDobleLlena(const ListaDoble *p);

int insertarAlFinalListaDoble(const ListaDoble *p, const void *d, unsigned tamElem);

int insertarAlInicioListaDoble(const ListaDoble *p, const void *d, unsigned tamElem);

int mostrarIzqADerListaDoble(const ListaDoble *p, void (* mostrar)(const void *));

int mostrarDerAIzqListaDoble(const ListaDoble *p, void (* mostrar)(const void *));

void ordenarListaDoble(ListaDoble *p, int (*comparar)(const void *, const void *));

int insertarEnOrdenListaDoble(ListaDoble *p,
                              const void *d,
                              unsigned tamElem,
                              int (*comparar)(const void *, const void *),
                              int (*acumular)(void **, unsigned *, const void *, unsigned));

int eliminarPorClaveListaDoble(ListaDoble *p,
                               void *d,
                               unsigned tamElem,
                               int (*comparar)(const void *, const void *));

#endif // LISTA_DOBLE_H_INCLUDED
