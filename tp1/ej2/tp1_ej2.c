#include <stdio.h>
#include "../ej1/tp1_ej1.h"
#include "tp1_ej2.h"

long calcular_combinatorio(int m, int n);

long tp1_ej2() {
    int numerador;
    int denominador;

    printf("Ingresa los numeros para calcular su combinatorio\n");
    printf("Numerador: ");
    scanf("%d", &numerador);
    fflush(stdin);
    printf("Denominador: ");
    scanf("%d", &denominador);
    fflush(stdin);

    while(numerador < denominador || denominador <= 0) {
        printf("Los numeros ingresados no són validos.\n");
        printf("El numerador debe ser mayor al denominador y el denominador debe ser mayor a 0.\n");
        printf("Numerador: ");
        scanf("%d", &numerador);
        fflush(stdin);
        printf("Denominador: ");
        scanf("%d", &denominador);
        fflush(stdin);
    }

    int combinatorio = calcular_combinatorio(numerador, denominador);
    printf("El combinatorio de %d y %d es %ld", numerador, denominador, combinatorio);
}

long calcular_combinatorio(int num, int den) {
    long factorial_numerador = calcular_factorial(num);
    long factorial_denominador = calcular_factorial(den) * calcular_factorial(num - den);
    return factorial_numerador / factorial_denominador;
}

bigint calcular_factorial(long);
