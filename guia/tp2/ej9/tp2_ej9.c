#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void grabar_numeros(FILE *pf, int cant_linea);

void tp2_ej9() {
    char linea_1 = 0; //cantidad de lineas con 1 elemento
    char linea_7 = 0; //cantidad de lineas con 7 elemento
    puts("Ingrese los valores enteros a grabar en el archivo. (S para salir)");
    srand(time(NULL));
    FILE *pf = fopen("tp2/ej9/tp1_ej9.txt", "wt");
    int i = 0;
    do {
        int cant_linea = rand() % 7 + 1;
        printf ("Enteros por linea: %d\n", cant_linea); // Valor entre 1 y 7
        grabar_numeros(pf, cant_linea);
        if(cant_linea == 1) {
            linea_1++;
        } else if (cant_linea == 7) {
            linea_7++;
        }
        i++;
    } while(linea_1 == 0 || linea_7 == 0);
    int cant_linea = rand() % 7 + 1;
    printf ("Enteros por linea: %d\n", cant_linea); // Valor entre 1 y 7
    grabar_numeros(pf, cant_linea);
    fclose(pf);
}

void grabar_numeros(FILE *pf, int cant_linea) {
    short int num;
    for(int i = 0; i < cant_linea; i++) {
        printf("> ");
        scanf("%hd", &num);
        fprintf(pf, "%6d", num);
        if(i < cant_linea - 1) {
            fputc(' ', pf);
        }
    }
    fputc('\n', pf);
}
