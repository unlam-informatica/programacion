#include "funciones.h"

size_t strlen_MIO(const char *s);

char toLower_MIO(const char c);

int isAlpha_MIO(const char c);

char * strchr_MIO(char *cad, int c);

static int contarOcurrencias(const char *cad, const char *sub, const int multiple);

int comparar_lineas(const char *linea1, const char *linea2);

static void hallarCantYMax(const char *linea, int *cant, int *max);


/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* FUNCIONES A DESARROLLAR                                            *//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

int contarOcurrencias1_MIO(const char *cad, const char *sub) {
    return contarOcurrencias(cad, sub, 1);
}

int contarOcurrencias2_MIO(const char *cad, const char *sub) {
    return contarOcurrencias(cad, sub, 0);
}

/**
    Cuenta la cantidad de ocurrencias (sin diferenciar mayusculas o minusculas)
     de la cadena `sub` en la cadena `cad`.
    El parametro `multiple` indica si al encontrar una subcadena `sub` en la cadena `cad`,
     se pueden reutilizar caracteres de la subcadena hallada
     o si se debe comenzar desde el caracter siguiente al final de la subcadena.

     Ejemplo:
     multiple == 0: "ana" aparece 1 vez en la cadena "anana".
     multiple != 0: "ana" aparece 2 veces en la cadena "anana".

     Parametros:
     cad: cadena a recorrer
     sub: subcadena a validar
     multiple: indica si se puede reutilizar subcadenas de cadenas ya encontradas.
*/
static int contarOcurrencias(const char *cad, const char *sub, const int multiple) {
    const char *psub = sub;
    size_t tamSub = strlen_MIO(psub);
    int cant = 0;
    if(tamSub == 0) {
        cant = 1;
    } else {
        const char *pcad = cad;
        size_t tamCad = strlen_MIO(pcad);
        const char *finCad = pcad + tamCad + 1;

        int iguales = 0;
        int pasos = 0;
        while(pcad < finCad - tamSub) {
            iguales = 1;
            pasos = 0;
            while(*psub && iguales == 1) {
                if(toLower_MIO(*pcad) != toLower_MIO(*psub)) {
                    iguales = 0;
                }
                pasos++;
                pcad++;
                psub++;
            }
            if(iguales == 1) {
                cant++;
            }
            if(multiple) {
                pcad = pcad - pasos + 1; // vuelvo a la posicion original y avanzo 1
            }
            psub -= pasos;
        }
    }
    return cant;
}


void rotarMat180_MIO(int m[][COLUM], int filas, int colum) {
    int aux;
    for(int i = 0; i < filas / 2; i++) {
        for(int j = 0; j < colum; j++) {
            aux = m[i][j];
            m[i][j] = m[filas - i - 1][colum - j - 1];
            m[filas - i - 1][colum - j - 1] = aux;
        }
    }
    if(filas % 2) {
        int fila_central = filas / 2;
        for(int j = 0; j < colum / 2; j++) {
            aux = m[fila_central][j];
            m[fila_central][j] = m[fila_central][colum - j - 1];
            m[fila_central][colum - j - 1] = aux;
        }
    }
}

int  mostrarMatTriangDerInf_MIO(int m[][COLUM], int filas, int colum) {
    int cont = 0;
    for(int i = 0; i < filas; i++) {
        int col_blanco = colum - i - 1;
        if(col_blanco > 0) {
            printf("%*s", col_blanco * 4, "");
            for(int j = i; j >= 0 && colum - j - 1 > 0; j--) {
                cont++;
                printf("%4d", m[i][colum - j - 1]);
            }
        } else {
            // Tengo igual o mas filas que columnas.
            // Muestro todas las columnas.
            for(int j = 0; j < colum; j++) {
                cont++;
                printf("%4d", m[i][j]);
            }
        }

        printf("\n");
    }
    return cont;
}

/**
    retorna -3 si se excedio el limite de la pila al cargar el archivo
*/
int ordenarArchivo_MIO(const char *archEnt, const char *archSal) {
    FILE *pe = fopen(archEnt, "rt");
    if(!pe) {
        return ERROR_ARCH_ENT;
    }

    tPila pila;
    tPila pila2;
    crearPila_MIO(&pila);
    crearPila_MIO(&pila2);
    char buffer[1000];
    char aux[1000];

    // leo del archivo de entrada, normalizo y cargo la pila principal.
    while(fgets(buffer, sizeof(buffer), pe)) {
        char *c = strchr_MIO(buffer, '\0');
        if(*--c != '\n') {
            *c++ = '\n';
            *c = '\0';
        }
        ponerEnPila_MIO(&pila, buffer, strlen_MIO(buffer));
    }
    fclose(pe);

    // Ordeno las lineas de menor a mayor en pila2
    while(sacarDePila_MIO(&pila, buffer, sizeof(buffer))) {
        while(verTope_MIO(&pila2, aux, sizeof(aux)) && comparar_lineas(buffer, aux) > 0) {
            sacarDePila_MIO(&pila2, aux, sizeof(aux));
            ponerEnPila_MIO(&pila, aux, sizeof(aux));
        }
        ponerEnPila_MIO(&pila2, buffer, sizeof(buffer));
    }

    // Guardo el resultado en un archivo de salida.
    // En caso de error de apertura, muestro por pantalla.
    FILE *ps = fopen(archSal, "wt");
    if(ps) {
        while(sacarDePila_MIO(&pila2, aux, sizeof(aux))) {
            fprintf(ps, "%s", aux);
        }
        fclose(ps);
    } else {
        while(sacarDePila_MIO(&pila2, aux, sizeof(aux))) {
            printf("%s", aux);
        }
        return ERROR_ARCH_SAL;
    }
    return 0;
}

/**
    Compara dos lineas y retorna cual es la menor basado en la cantidad de palabras.
    Si las dos lineas contienen la misma cantidad de palabras, se tiene en cuenta
     la palabra mas larga

    Retorna
    un numero negativo si linea1 es menor que linea2
    0 si son iguales
    un numero positivo si linea1 es mayor que linea2
*/
int comparar_lineas(const char *linea1, const char *linea2) {
    int cant1 = 0;
    int cant2 = 0;
    int max1 = 0;
    int max2 = 0;

    hallarCantYMax(linea1, &cant1, &max1);
    hallarCantYMax(linea2, &cant2, &max2);

    return cant1 < cant2 ? -1 : cant1 > cant2 ? 1 : max1 - max2;
}

/**
    Halla la cantidad de palabras y la cantidad de letras que posee la palabra
     mas larga en la linea indicada.

    Parametros:
     linea: cadena de caracteres a validar
     cant: puntero a una variable entera para alojar la cantidad de palabras
     max: puntero a una variable entera para alojar la cantidad de letras en la palabra mas larga
*/
static void hallarCantYMax(const char *linea, int *cant, int *max){
    int maxAux = 0;
    const char *cad = linea;
    while(*cad && *cad != '\n') {
        if(isAlpha_MIO(*cad++)) {
            maxAux++;
            if(!isAlpha_MIO(*cad)) {
                (*cant)++;
                if(maxAux > *max) {
                    *max = maxAux;
                }
                maxAux = 0;
            }
        }
    }
}

/*
 * Primitivas Pila Estatica
 */

void crearPila_MIO(tPila *p) {
    p->tope = TAM_PILA;
}


int pilaLlena_MIO(const tPila *p, unsigned cantBytes) {
    return p->tope < cantBytes + sizeof(unsigned);
}


int ponerEnPila_MIO(tPila *p, const void *d, unsigned cantBytes) {
    if(p->tope < cantBytes + sizeof(unsigned))
        return 0;
    p->tope -= cantBytes;
    memcpy(p->pila + p->tope, d, cantBytes);
    p->tope -= sizeof(unsigned);
    memcpy(p->pila + p->tope, &cantBytes, sizeof(unsigned));
    return 1;
}


int verTope_MIO(const tPila *p, void *d, unsigned cantBytes) {
    unsigned tamInfo;

    if(p->tope == TAM_PILA) {
        return 0;
    }
    memcpy(&tamInfo, p->pila + p->tope, sizeof(unsigned));
    memcpy(d, p->pila + p->tope + sizeof(unsigned), cantBytes <= tamInfo ? cantBytes : tamInfo);
    return 1;
}


int pilaVacia_MIO(const tPila *p) {
    return p->tope == TAM_PILA;
}


int sacarDePila_MIO(tPila *p, void *d, unsigned cantBytes) {
    unsigned tamInfo;

    if(p->tope == TAM_PILA)
        return 0;
    memcpy(&tamInfo, p->pila + p->tope, sizeof(unsigned));
    p->tope += sizeof(unsigned);
    memcpy(d, p->pila + p->tope, cantBytes <= tamInfo ? cantBytes : tamInfo);
    p->tope += tamInfo;
    return 1;
}


void vaciarPila_MIO(tPila *p) {
    p->tope = TAM_PILA;
}

/*
 *   Funciones utilitarias
 */
size_t strlen_MIO(const char *s) {
    size_t count = 0L;
    while(*s++) count++;
    return count;
}

char toLower_MIO(const char c) {
    return (c >= 'A' && c <= 'Z') ? c + 32 : c;
}

int isAlpha_MIO(const char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

char * strchr_MIO(char *cad, int c){
    char *pcad = cad;
    while(*pcad && *cad != c){
        pcad++;
    }
    return c == 0 || *pcad != 0 ? pcad : NULL;
}

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
