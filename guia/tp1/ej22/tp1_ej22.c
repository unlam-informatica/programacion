#include <stdio.h>

#include "tp1_ej22.h"

#define TAM 8

int insertar(int *arr, int pos, int elem);

// Desarrollar una función que inserte un elemento en un arreglo de enteros, dada la posición de inserción.
int tp1_ej22() {
    int vec[TAM] = {3, 3, 3, 3, 3, 3, 3, 3};
    printf("%p\n", vec);
    printf("%p\n\n\n", vec + TAM);
    for (int *p = vec; p != (vec + TAM); p++) {
        printf("%p\t%d\n", p, *p);
    }
    puts("\n");
    insertar(vec, 3, 5);
    for (int *p = vec; p != (vec + TAM); p++) {
        printf("%p\t%d\n", p, *p);
    }
    return 0;
}

int insertar(int *arr, int pos, int elem) {
    *(arr + pos) = elem;
    return 0;
}
