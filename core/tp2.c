#include <stdio.h>

#include "tp2.h"
#include "../tp2/ej1/tp2_ej1.h"

void correr_ejercicio_tp2(int ej) {
    switch(ej) {
    case 1:
        tp2_ej1();
        break;
    default:
        printf("El número de ejercicio no existe o aun no fue implementado.");
    }
}
