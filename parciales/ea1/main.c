
#include "main.h"

int main()
{
    probarCadenas();

    probarMatrices();

    probarArchivosYPila();

    return 0;
}


void probarCadenas()
{
    char   *cad[2] = { "Es El Anana De Ana Y La Manzana De Juana y de Susana",
                       "aAaAAaAA"  },
           *sub[]  = { "ANA", " ", " de ", "", "aa" };
    int     veces1,
            veces2,
            ciclo;

    printf("Buscando en la cadena \"%s\".\n", cad[0]);
    ciclo = 0;
    while(ciclo < 4)
    {
        veces1 = contarOcurrencias1(cad[0], sub[ciclo]);
        veces2 = contarOcurrencias2(cad[0], sub[ciclo]);
        printf("Se encontro %2d y %2d veces la subcadena \"%s\".\n",
               veces1, veces2, sub[ciclo]);
        ciclo++;
    }
    veces1 = contarOcurrencias1(cad[1], sub[ciclo]);
    veces2 = contarOcurrencias2(cad[1], sub[ciclo]);
    printf("Finalmente en \"%s\" se encuentra \"%s\" %2d y %2d veces.\n",
            cad[1], sub[ciclo], veces1, veces2);

    puts("/////////////////////////////////////////////////");

/**  quite estos comentarios para probar su solución **/
    printf("Buscando en la cadena \"%s\".\n", cad[0]);
    ciclo = 0;
    while(ciclo < 4)
    {
        veces1 = contarOcurrencias1_MIO(cad[0], sub[ciclo]);
        veces2 = contarOcurrencias2_MIO(cad[0], sub[ciclo]);
        printf("Se encontro %2d y %2d veces la subcadena \"%s\".\n",
               veces1, veces2, sub[ciclo]);
        ciclo++;
    }
    veces1 = contarOcurrencias1_MIO(cad[1], sub[ciclo]);
    veces2 = contarOcurrencias2_MIO(cad[1], sub[ciclo]);
    printf("Finalmente en \"%s\" se encuentra \"%s\" %2d y %2d veces.\n",
            cad[1], sub[ciclo], veces1, veces2);

    puts("/////////////////////////////////////////////////\n");
}


void probarMatrices()
{
    int     mat[FILAS][COLUM];

    /**
    cargarMatConsec(mat, FILAS, COLUM);
    printf("La matriz cargada con valores consecutivos es:\n");
    mostrarMat(mat, FILAS, COLUM);
    printf("La matriz rotada en 180 grados queda:\n");
    rotarMat180(mat, FILAS, COLUM);
    mostrarMat(mat, FILAS, COLUM);
    printf("Los elementos de la matriz rotada que pertenecen\n"
           "o estan por debajo de la diagonal secundaria son:\n");
    mostrarMatTriangDerInf(mat, FILAS, COLUM);
    **/
    puts("/////////////////////////////////////////////////");
/**  quite estos comentarios para probar su solución  **/
    cargarMatConsec(mat, FILAS, COLUM);
    printf("(MIO)\nLa matriz rotada en 180 grados queda:\n");
    rotarMat180_MIO(mat, FILAS, COLUM);
    mostrarMat(mat, FILAS, COLUM);
    printf("(MIO)\nLos elementos de la matriz rotada que pertenecen\n"
           "o estan por debajo de la diagonal secundaria son:\n");
    mostrarMatTriangDerInf_MIO(mat, FILAS, COLUM);

    puts("/////////////////////////////////////////////////\n");
}


void probarArchivosYPila()
{
    int valDevuelto;

    if(!crearArchivo(ARCH_ENT))
        fprintf(stderr, "ERROR - creando archivo de texto \"%s\"\n", ARCH_ENT);
    else
    {
        mostrarArchivo(ARCH_ENT);

    /// probar eliminando el archivo
    /// unlink(ARCH_ENT);

    /// probar inhibiendo la creación del archivo
    /// inhibirArchivo(ARCH_SAL);

    /// pruebe acá con su propia versión en lugar de la mía
        valDevuelto = ordenarArchivo_MIO(ARCH_ENT, ARCH_SAL);
        valDevuelto = ordenarArchivo(ARCH_ENT, ARCH_SAL);
        if(valDevuelto == ERROR_ARCH_ENT)
        {
            fprintf(stderr, "ERROR - No existe el archivo a leer.\n");
            return;
        }
        if(valDevuelto == ERROR_ARCH_SAL)
        {
            fprintf(stderr, "ERROR - No se pudo crear el archivo de salida.\n");
            habilitarArchivo(ARCH_SAL);
        }
        else
            mostrarArchivo(ARCH_SAL);
    }
    puts("/////////////////////////////////////////////////\n");
}
