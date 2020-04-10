#include <stdio.h>
#include <math.h>

#include "tp1_ej3.h"
#include "../ej1/tp1_ej1.h"

double calcular_exponencial(int x, float tol);


double tp1_ej3() {
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
    printf("x: %d, tol: %f\n", x, tol);
    for(int i=1; tol_actual > tol; i++) {
        printf("i: %d - ", i);
        printf("pow(%d, %d): %f - ", x, i, pow(x, i));
        printf("calcular_factorial(%d): %llu - ", i, calcular_factorial(i));

        tol_actual = fabs(pow(x, i) / calcular_factorial(i));
        printf("tol actual: %f - ", tol_actual);

        exponencial += tol_actual;
        printf("Valor actual: %f\n", exponencial);
    }
    return exponencial;
}
