#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include "tp1.h"

int main() {
    // Seteamos locale para poder utilizar acentos directamente en printf
    setlocale(LC_ALL, "");
    printf("=========================================\n");
    printf("  Ejercicios Programación 1 - Guía 2020  \n");
    printf("=========================================\n");

    int tp = 0;
    int ej = 0;
    do {
        printf("Selecciona el TP a ejecutar (0 para salir): ");
        scanf("%d", &tp);
        if(tp != 0) {
            if(tp != 1 && tp != 2 && tp != 3) {
                printf("\nEl número de TP no existe!\n\n");
            } else {
                printf("\n******************* TP%d *******************\n", tp);
                printf("Indica el ejercicio a ejecutar: ");
                scanf("%d", &ej);
                fflush( stdin );
                switch(tp) {
                case 1:
                    correr_ejercicio_tp1(ej);
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

