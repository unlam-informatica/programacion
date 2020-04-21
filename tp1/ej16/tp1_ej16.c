#include <stdio.h>

#include "tp1_ej16.h"
#include "../../core/fecha.h"
#include "../../core/utils.h"

// Desarrollar una función que a partir de una fecha obtenga la que resulte de sumarle N días.
int tp1_ej16() {
    imprimir_titulo("TP1 - EJ16");

    int dia=0, mes=0, anio=0, dias_a_sumar=0;
    printf("> Ingresa la fecha de inicio: (formato DD-MM-AAAA): ");
    scanf("%d-%d-%d", &dia, &mes, &anio);
    fflush(stdin);
    printf("> Indica la cantidad de días a sumar a la fecha): ");
    scanf("%d", &dias_a_sumar);
    fflush(stdin);

    Fecha fecha = {dia, mes, anio};
    while(!es_fecha_valida(&fecha)) {
        puts("Fecha inválida!");
        printf("> Ingresa la fecha de inicio: (formato DD-MM-AAAA): ");
        scanf("%d-%d-%d", &dia, &mes, &anio);
        fflush(stdin);
        fecha = (Fecha) {
            dia, mes, anio
        };
    }
    while(dias_a_sumar < 0) {
        puts("Los días a sumar deben ser un número positivo");
        printf("> Indica la cantidad de días a sumar a la fecha): ");
        scanf("%d", &dias_a_sumar);
        fflush(stdin);
    }

    Fecha nueva_fecha = sumar_dias(&fecha, dias_a_sumar);
    printf("Fecha ingresada: %02d-%02d-%02d\n", fecha.dia, fecha.mes, fecha.anio);
    printf("Fecha calculada: %02d-%02d-%02d\n", nueva_fecha.dia, nueva_fecha.mes, nueva_fecha.anio);
    return 0;
}

