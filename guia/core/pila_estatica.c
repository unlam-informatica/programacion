#include "pila_estatica.h"

void crear_pila(PilaEstatica *p) {
    p->tope = TAM_PILA;
}

int pila_llena(const PilaEstatica *p, unsigned cant_bytes) {
    return p->tope < cant_bytes + sizeof(unsigned);
}

int poner_en_pila(PilaEstatica *p, const void *d, unsigned cant_bytes) {
    if(p->tope < cant_bytes + sizeof(unsigned))
        return 0;
    p->tope -= cant_bytes;
    memcpy(p->pila + p->tope, d, cant_bytes);
    p->tope -= sizeof(unsigned);
    memcpy(p->pila + p->tope, &cant_bytes, sizeof(unsigned));
    return 1;
}

int ver_tope(const PilaEstatica *p, void *d, unsigned cant_bytes) {
    unsigned tamInfo;

    if(p->tope == TAM_PILA){
        return 0;
    }
    memcpy(&tamInfo, p->pila + p->tope, sizeof(unsigned));
    memcpy(d, p->pila + p->tope + sizeof(unsigned), minimo(cant_bytes, tamInfo));
    return 1;
}

int pilaVacia(const PilaEstatica *p) {
    return p->tope == TAM_PILA;
}

int sacarDePila(PilaEstatica *p, void *d, unsigned cant_bytes) {
    unsigned tamInfo;

    if(p->tope == TAM_PILA)
        return 0;
    memcpy(&tamInfo, p->pila + p->tope, sizeof(unsigned));
    p->tope += sizeof(unsigned);
    memcpy(d, p->pila + p->tope, minimo(cant_bytes, tamInfo));
    p->tope += tamInfo;
    return 1;
}

void vaciarPila(PilaEstatica *p) {
    p->tope = TAM_PILA;
}
