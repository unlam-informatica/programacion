#include <stdio.h>
#include "../../core/utils.h"
#include "../../core/fecha.h"
#include "tp1_ej14.h"


//Desarrollar una función que determine si una fecha es formalmente correcta
int tp1_ej14() {
    imprimir_titulo("TP1 - EJ14");

    int dia=0, mes=0, anio=0;
    printf("Ingresa la fecha a validar (formato DD-MM-AAAA): ");
    scanf("%d-%d-%d", &dia, &mes, &anio);
    fflush(stdin);

    Fecha fecha = {dia, mes, anio};
    printf("La fecha ingresada es %s!", es_fecha_valida(&fecha) ? "válida" : "inválida");
    return 0;
}
