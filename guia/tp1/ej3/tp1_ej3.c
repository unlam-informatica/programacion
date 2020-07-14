#include <stdio.h>
#include <math.h>

#include "tp1_ej3.h"

#include "../../core/utils.h"
#include "../ej1/tp1_ej1.h"

double calcular_exponencial(int x, float tol);


double tp1_ej3() {
    imprimir_titulo("TP1 - EJ1");
    int x;
    float tol;

    printf("Ingresa los numeros para calcular su exponencial.\n");
    printf("Exponente: ");
    scanf("%d", &x);
    fflush(stdin);

    printf("Tolerancia: ");
    scanf("%f", &tol);
    fflush(stdin);

    while(tol <= 0 || tol >= 1) {
        printf("La tolerancia debe ser mayor a 0 y menor a 1.\n");

        printf("Exponente: ");
        scanf("%d", &x);
        fflush(stdin);

        printf("Tolerancia: ");
        scanf("%f", &tol);
        fflush(stdin);
    }

    double exponencial = calcular_exponencial(x, tol);
    printf("El exponencial de %d es %f", x, exponencial);
    return exponencial;
}

double calcular_exponencial(int x, float tol) {
    double tol_actual = 1;
    double exponencial = 1;

    for(int i=1; tol_actual > tol; i++) {
        tol_actual = fabs(pow(x, i) / calcular_factorial(i));
        exponencial += tol_actual;
    }

    return exponencial;
}
