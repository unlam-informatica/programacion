#include <stdio.h>

#include "tp2.h"
#include "../tp2/ej1/tp2_ej1.h"
#include "../tp2/ej9/tp2_ej9.h"
#include "../tp2/ej13/tp2_ej13.h"

void correr_ejercicio_tp2(int ej) {
    switch(ej) {
    case 1:
        tp2_ej1();
        break;
    case 9:
        tp2_ej9();
        break;
    case 13:
        tp2_ej13();
        break;
    default:
        printf("El número de ejercicio no existe o aun no fue implementado.");
    }
}
