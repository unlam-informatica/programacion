#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#include "menu.h"

/**
    Escriba una función que permita desplegar un menú de opciones, devolviendo una opción válida.
*/
char mostrar_menu(const char *menu, const char *opciones) {
    char opc;
    fflush(stdin);
    printf("%s> ", menu);
    scanf("%c", &opc);
    while(strchr(opciones, opc) == NULL) {
        printf("%s\n%s\n> ", "Opción no valida!", menu);
        fflush(stdin);
        scanf("%c", &opc);
    }
    return opc;
}
