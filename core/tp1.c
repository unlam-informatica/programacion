#include "tp1.h"
#include "../tp1/ej1/tp1_ej1.h"

void correr_ejercicio_tp1(int ej) {
    switch(ej) {
    case 1:
        tp1_ej1(1);
        break;
    default:
        printf("El número de ejercicio no existe o aún no fue implementado.");
    }
}
