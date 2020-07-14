//#include <stdio.h>
//
//#include "pila_dinamica.h"
//
//#define minimo( X , Y ) ( ( X ) <= ( Y ) ? ( X ) : ( Y ) )
//
//void crear_pila(PilaDinamica *p) {
//    *p = NULL;
//}
//
//int pila_llena(const PilaDinamica *p, unsigned cant_bytes) {
//    Nodo *aux = (Nodo *) malloc(sizeof(Nodo));
//    void *info = malloc(cant_bytes);
//
//    free(aux);
//    free(info);
//    return aux == NULL || info == NULL;
//}
//
//int poner_en_pila(PilaDinamica *p, const void *d, unsigned cant_bytes) {
//    Nodo *nue;
//
//    if((nue = (Nodo *)malloc(sizeof(Nodo))) == NULL || (nue->info = malloc(cant_bytes)) == NULL) {
//        free(nue);
//        return 0;
//    }
//    memcpy(nue->info, d, cant_bytes);
//    nue->tamInfo = cant_bytes;
//    nue->sig = *p;
//    *p = nue;
//    return 1;
//}
//
//int ver_tope(const PilaDinamica *p, void *d, unsigned cant_bytes) {
//    if(*p == NULL)
//        return 0;
//    memcpy(d, (*p)->info, minimo(cant_bytes, (*p)->tamInfo));
//    return 1;
//}
//
//int pila_vacia(const PilaDinamica *p) {
//    return *p == NULL;
//}
//
//int sacar_de_pila(PilaDinamica *p, void *d, unsigned cant_bytes) {
//    Nodo *aux = *p;
//
//    if(aux == NULL) {
//        return 0;
//    }
//    *p = aux->sig;
//    memcpy(d, aux->info, minimo(cant_bytes, aux->tamInfo));
//    free(aux->info);
//    free(aux);
//    return 1;
//}
//
//void vaciar_pila(PilaDinamica *p) {
//    while(*p) {
//        Nodo *aux = *p;
//        *p = aux->sig;
//        free(aux->info);
//        free(aux);
//    }
//}
