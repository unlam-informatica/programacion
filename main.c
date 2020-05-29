#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "core/tp1.h"
#include "core/tp2.h"

int main(int cargs, char **varg, char **vent) {
    // Seteamos locale para poder utilizar acentos directamente en printf
    setlocale(LC_ALL, "");
    puts("=========================================");
    puts("  Ejercicios Programación 1 - Guia 2020  ");
    puts("=========================================");

    int tp = 0;
    int ej = 0;
    do {
        printf("Indica el TP a ejecutar (0 para salir): ");
        fflush(stdin);
        scanf("%d", &tp);
        if(tp != 0) {
            if(tp != 1 && tp != 2 && tp != 3) {
                printf("\nEl número de TP no existe!\n\n");
            } else {
                printf("\n>>>>> TP%d\n", tp);
                printf("> Indica el ejercicio a ejecutar: ");
                scanf("%d", &ej);
                fflush(stdin);
                switch(tp) {
                case 1:
                    correr_ejercicio_tp1(ej);
                    break;
                case 2:
                    correr_ejercicio_tp2(ej);
                    break;
                default:
                    printf("El número de TP no existe.");
                }
            }
            printf("\n**************************************************\n");
        }
    } while(tp != 0);
    return 0;
}

