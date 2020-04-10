#include <stdio.h>
#include "tp1_ej1.h"
#include "../../core/types.h"

long solicitar_numero();
bigint calcular_factorial(long num);

bigint tp1_ej1() {
    printf("**************** TP1 - EJ1 *******************\n");

    long num = solicitar_numero();
    long factorial = calcular_factorial(num);
    printf("Factorial de %ld: %ld\n", num, factorial);
    return factorial;
}

long solicitar_numero() {
    long ingreso;
    printf("Ingresa un número positivo para calcular su factorial: ");
    scanf("%ld", &ingreso);
    fflush(stdin);
    while(ingreso < 0) {
        printf("Por favor ingresa un número válido: ");
        scanf("%ld", &ingreso);
        fflush(stdin);
    }
    return ingreso;
}

bigint calcular_factorial(long num) {
    if(num != 0) {
        return calcular_factorial(num - 1) * num;
    } else {
        return 1;
    }
}
