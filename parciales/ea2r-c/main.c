
#include "main.h"

int main()
{
    FILE   *fpPant = fopen("pantalla.txt", "wt");
//    FILE   *fpPant = stdout;

    if(fpPant == NULL)      // si no puede abrir el archivo
        fpPant = stdout;        // mostrará por consola

    probarPrimitivasUno(fpPant);

    probarPrimitivasDos(fpPant);

    if(fpPant != stdout && fpPant != stderr && fpPant != NULL)
    {
        fclose(fpPant);
        system("start notepad pantalla.txt");
    }
    return 0;
}


void probarPrimitivasUno(FILE *fpPant)
{
    tLista  lista;
    int     cant,
            cantUnic,
            cantRepe;

    fprintf(fpPant,
            "Primera Prueba - Eliminar Unicos y luego Repetidos.\n"
            "======= ======   ======== ====== = ===== =========\n");
    cant = crearYcargarLista(&lista);
    fprintf(fpPant, "En la lista hay %d examenes finales.\n\n", cant);
    fprintf(fpPant, "Mostrando los examenes finales.\n");
    cant = mostrarLista(&lista, mostrarFinal, fpPant);
    fprintf(fpPant, "Se mostraron %d examenes finales.\n\n", cant);

    fprintf(fpPant, "Eliminar y mostrar los que dieron mas de un final.\n");
    cantRepe = eliminarYMostrarRepetidos(&lista, fpPant, compararFinal, mostrarFinal);
    fprintf(fpPant, "Se eliminaron %d nodos repetidos.\n\n", cantRepe);

    fprintf(fpPant, "Eliminar y mostrar los que dieron un solo final.\n");
    cantUnic = eliminarYMostrarUnicos_MIO(&lista, fpPant, compararFinal, mostrarFinal);
    fprintf(fpPant, "Se eliminaron %d nodos unicos.\n\n\n", cantUnic);
}


void probarPrimitivasDos(FILE *fpPant)
{
    tLista  lista;
    int     cant,
            cantUnic,
            cantRepe;

    fprintf(fpPant,
            "Segunda Prueba - Eliminar Repetidos y luego Unicos.\n"
            "======= ======   ======== ========= = ===== ======\n");
    cant = crearYcargarLista(&lista);
    fprintf(fpPant, "En la lista hay %d examenes finales.\n\n", cant);
    fprintf(fpPant, "Mostrando los examenes finales.\n");
    cant = mostrarLista(&lista, mostrarFinal, fpPant);
    fprintf(fpPant, "Se mostraron %d examenes finales.\n\n", cant);

    fprintf(fpPant, "Eliminar y mostrar los que dieron un solo final.\n");
    cantUnic = eliminarYMostrarUnicos_MIO(&lista, fpPant, compararFinal, mostrarFinal);
    fprintf(fpPant, "Se eliminaron %d nodos unicos.\n\n", cantUnic);

    fprintf(fpPant, "Eliminar y mostrar los que dieron mas de un final.\n");
    cantRepe = eliminarYMostrarRepetidos(&lista, fpPant, compararFinal, mostrarFinal);
    fprintf(fpPant, "Se eliminaron %d nodos repetidos.\n", cantRepe);
}

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
