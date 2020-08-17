#ifndef PilaEstatica_ESTATICA_INCLUDED
#define PilaEstatica_ESTATICA_INCLUDED

#define TAM_PILA 500
#define minimo(X, Y) ((X) <= (Y) ? (X) : (Y))

typedef struct
{
    char pila[TAM_PILA];
    unsigned tope;
} PilaEstatica;

void crearPila(PilaEstatica *p);

int PilaLlena(const PilaEstatica *p, unsigned cantBytes);

int ponerEnPila(PilaEstatica *p, const void *d, unsigned cantBytes);

int verTope(const PilaEstatica *p, void *d, unsigned cantBytes);

int PilaVacia(const PilaEstatica *p);

int sacarDePila(PilaEstatica *p, void *d, unsigned cantBytes);

void vaciarPila(PilaEstatica *p);

#endif // PilaEstatica_ESTATICA_INCLUDED
