#include <stdio.h>

#include "../../core/utils.h"
#include "../../core/fecha.h"

int tp1_ej15() {
    imprimir_titulo("TP1 - EJ15");

    int dia=0, mes=0, anio=0;
    printf("Ingresa la fecha para calcular su día siguiente (formato DD-MM-AAAA): ");
    scanf("%d-%d-%d", &dia, &mes, &anio);
    fflush(stdin);

    Fecha fecha = {dia, mes, anio};
    while(!es_fecha_valida(&fecha)) {
        puts("Fecha inválida!");
        printf("Ingresa la fecha para calcular su día siguiente (formato DD-MM-AAAA): ");
        scanf("%d-%d-%d", &dia, &mes, &anio);
        fflush(stdin);
    }

    Fecha nueva_fecha = dia_siguiente(&fecha);
    printf("Fecha ingresada: %02d-%02d-%02d\n", fecha.dia, fecha.mes, fecha.anio);
    printf("Día siguiente: %02d-%02d-%02d\n", nueva_fecha.dia, nueva_fecha.mes, nueva_fecha.anio);
    return 0;
}

