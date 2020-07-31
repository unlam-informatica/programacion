#include <stdio.h>

#include "tp1.h"
#include "../tp1/ej1/tp1_ej1.h"
#include "../tp1/ej2/tp1_ej2.h"
#include "../tp1/ej3/tp1_ej3.h"
#include "../tp1/ej14/tp1_ej14.h"
#include "../tp1/ej15/tp1_ej15.h"
#include "../tp1/ej16/tp1_ej16.h"
#include "../tp1/ej18/tp1_ej18.h"
#include "../tp1/ej22/tp1_ej22.h"

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
    case 15:
        tp1_ej15();
        break;
    case 16:
        tp1_ej16();
        break;
    case 18:
        tp1_ej18();
        break;
    case 22:
        tp1_ej22();
        break;
    default:
        printf("El número de ejercicio no existe o aún no fue implementado.");
    }
}
