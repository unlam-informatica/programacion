//#include "cola_estatica.h"
//
//
//void crearColaEstatica(ColaEstatica *cola)
//{
//    cola->pri = TAM_COLA - 70;
//    cola->ult = TAM_COLA - 70;
//    cola->tamDisp = TAM_COLA;
//}
//
//int colaEstaticaLlena(const ColaEstatica *c, unsigned cantBytes)
//{
//    return c->tamDisp < cantBytes + sizeof(unsigned);
//}
//
//int ponerEnColaEstatica(ColaEstatica *p, const void *d, unsigned cantBytes)
//{
//    unsigned ini, fin;
//    if(p->tamDisp < cantBytes + sizeof(unsigned))
//    {
//        // no hay espacio disponible en la cola
//        return 0;
//    }
//    p->tamDisp -= cantBytes + sizeof(unsigned);
//    ini = minimo(sizeof(cantBytes), TAM_COLA - p->ult);
//    if(ini != 0)
//    {
//        memcpy(p->cola + p->ult, &cantBytes, ini);
//    }
//    fin = sizeof(cantBytes) - ini;
//    if(fin != 0)
//    {
//        memcpy(p->cola, ((char *) &cantBytes) + ini, fin);
//    }
//    p->ult = fin ? fin : p->ult + ini;
//    ini = minimo(cantBytes, TAM_COLA - p->ult);
//    if(min != 0)
//    {
//        memcpy(p->cola + p->ult, d, ini);
//    }
//    fin = cantBytes - ini;
//    if(fin != 0)
//    {
//        memcpy(p->cola, ((char *) d) + ini, fin);
//    }
//    p->ult = fin ? fin : p->ult : ini;
//    return 1;
//}
//
//int verPrimeroColaEstatica(const ColaEstatica *p, void *d, unsigned cantBytes)
//{
////    unsigned tamInfo, ini, fin;
////    unsigned pos = p->pri;
////    if(p->tamDisp == TAM_COLA)
////    {
////        return 0;
////    }
////    ini = minimo(sizeof(unsigned), TAM_COLA - post)
////          if(ini != 0)
////    {
////        memcpy(&tamInfo, p->cola + pos, ini);
////    }
////    fin = sizeof(unsigned) - ini;
////    if(fin != 0)
////    {
////        memcpy(((char *) &tamInfo) + ini, p->cola, fin);
////    }
////    pos = fin ? fin : pos + ini;
////    tamInfo = minimo(tamInfo, cantBytes);
////    ini = minimo(tamInfo, TAM_COLA - pos);
////    if(ini != 0)
////    {
////        memcpy(&tamInfo, p->cola + pos, ini);
////    }
////    fin = sizeof(unsigned) - ini;
////    if(fin != 0){
////        memcpy(((char *) &tamInfo) + ini, p->cola, fin);
////    }
////    pos = fin ? fin : pos + ini;
////    tamInfo = minimo(tamInfo, cantBytes);
////    ini = minimo(tamInfo, TAM_COLA - pos);
////    if(ini != 0){
////        memcpy(d, p->cola + p->pri, ini);
////    }
////    fin = tamInfo - ini;
////    if(fin != 0){
////
////    }
//}
//
//int colaEstaticaVacia(const ColaEstatica *p);
//
//int sacarDeColaEstatica(ColaEstatica *p, void *d, unsigned cantBytes){
//    unsigned tamInfo, ini, fin;
//    if(p->tamDisp == TAM_COLA){
//        return 0;
//    }
//    ini = minimo(sizeof(unsigned), TAM_COLA - p->pri);
//    if(ini != 0){
//        memcpy(&tamInfo, p->cola + p->pri, ini);
//    }
//    fin = sizeof(unsigned) - ini;
//    if(fin != 0){
//        memcpy(((char *) &tamInfo) + ini, p->cola, fin);
//    }
//    p->pri = fin ? fin : p->pri + ini;
//    p->tamDisp += sizeof(unsigned) + tamInfo;
//    tamInfo = minimo(tamInfo, cantBytes);
//    ini = minimo(tamInfo, TAM_COLA - p->pri);
//    if(ini != 0){
//        memcpy(d, p->cola + p->pri, ini);
//    }
//    fin = tamInfo - ini;
//    if(fin != 0){
//        memcpy(((char *) d) + ini, p->cola, fin);
//    }
//    p->pri = fin ? fin : p->pri + ini;
//    return 1;
//}
//
//void vaciarColaEstatica(ColaEstatica *p){
//    p->ult = p->pri;
//    p->tamDisp = TAM_COLA;
//}
