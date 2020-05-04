#include <stdio.h>

#include "tp1_ej17.h"
#include "../../core/fecha.h"

// Desarrollar una función que a partir de una fecha obtenga la que resulta de restarle N días.
int tp1_ej17() {
    Fecha fecha = {1,1,2020};
    restar_dias(&fecha, 100);
    return -1;
}
