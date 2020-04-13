#include <stdio.h>

#include "tp1.h"
#include "../tp1/ej1/tp1_ej1.h"
#include "../tp1/ej2/tp1_ej2.h"
#include "../tp1/ej3/tp1_ej3.h"
#include "../tp1/ej14/tp1_ej14.h"

void correr_ejercicio_tp1(int ej) {
    switch(ej) {
    case 1:
        tp1_ej1();
        break;
    case 2:
        tp1_ej2();
        break;
    case 3:
        tp1_ej3();
        break;
    case 14:
        tp1_ej14();
        break;
    default:
        printf("El n�mero de ejercicio no existe o a�n no fue implementado.");
    }
}
