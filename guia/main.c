#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "core/tp1.h"
#include "core/tp2.h"

int comparar_lineas(const char *linea1, const char *linea2);

int _isAlpha(const char c);

int main(int cargs, char **varg, char **vent) {
    // Seteamos locale para poder utilizar acentos directamente en printf
//    setlocale(LC_ALL, "");
//    puts("=========================================");
//    puts("  Ejercicios Programación 1 - Guia 2020  ");
//    puts("=========================================");
//
//    int tp = 0;
//    int ej = 0;
//    do {
//        printf("Indica el TP a ejecutar (0 para salir): ");
//        fflush(stdin);
//        scanf("%d", &tp);
//        if(tp != 0) {
//            if(tp != 1 && tp != 2 && tp != 3) {
//                printf("\nEl número de TP no existe!\n\n");
//            } else {
//                printf("\n>>>>> TP%d\n", tp);
//                printf("> Indica el ejercicio a ejecutar: ");
//                scanf("%d", &ej);
//                fflush(stdin);
//                switch(tp) {
//                case 1:
//                    correr_ejercicio_tp1(ej);
//                    break;
//                case 2:
//                    correr_ejercicio_tp2(ej);
//                    break;
//                default:
//                    printf("El número de TP no existe.");
//                }
//            }
//            printf("\n**************************************************\n");
//        }
//    } while(tp != 0);
    char linea1[] = "     mientras palpite mi fiel corazon.                 \n";
    char linea2[] = "     jurando amarte, como asi defenderte,              \n";
    int res = comparar_lineas(linea1, linea2);
    int res2 = comparar_lineas(linea2, linea1);
    printf("Resultado: %d", res);
    printf("Resultado2: %d", res2);
    return 0;
}

int comparar_lineas(const char *linea1, const char *linea2) {
    const char *l1 = linea1;
    const char *l2 = linea2;
    int count1 = 0;
    int count2 = 0;
    int maxAux = 0;
    int max1 = 0;
    int max2 = 0;
    int dentro = 0;

    while(*l1) {
        if(_isAlpha(*l1)) {
            dentro = 1;
            maxAux++;
        } else if(dentro) {
            count1++;
            dentro = 0;
            if(maxAux > max1) {
                max1 = maxAux;
            }
            maxAux = 0;
        }
        l1++;
    }
    maxAux = 0;
    dentro = 0;
    while(*l2) {
        if(_isAlpha(*l2)) {
            dentro = 1;
            maxAux++;
        } else if(dentro) {
            count2++;
            dentro = 0;
            if(maxAux > max2) {
                max2 = maxAux;
            }
                maxAux = 0;
        }
        l2++;
    }

    return count1 < count2 ? -1 : count1 > count2 ? 1 : max1 - max2;
}


int _isAlpha(const char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}
