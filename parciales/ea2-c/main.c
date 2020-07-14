#include "main.h"

int main()
{
    FILE   *fpPant = fopen("pantalla.txt", "wt");
    tLista  lista;
    int     cant,
            cantElim;

    if(fpPant == NULL)      // si no puede abrir el archivo
        fpPant = stdout;        // mostrará por consola

    cant = crearYcargarLista(&lista);
    fprintf(fpPant,
            "En la lista hay %d movimientos bancarios.\n\n",
            cant);

//    cant = mostrarLista(&lista, mostrarMovim, fpPant);
    cant = mostrarLista_MIO(&lista, mostrarMovim_MIO, fpPant);

    fprintf(fpPant,
            "Se mostraron %d movimientos bancarios de la lista.\n\n",
            cant);


    fprintf(fpPant, "Ordenando por número de cuenta.\n");
//    ordenarLista(&lista, compararMovim);
    ordenarLista_MIO(&lista, compararMovim_MIO);

//    if(cant != mostrarLista(&lista, mostrarMovim, fpPant))
    if(cant != mostrarLista_MIO(&lista, mostrarMovim_MIO, fpPant))
    {
        fprintf(fpPant, "Ups!!! - Faltan cuentas.\n");
    }
    else
    {
        fprintf(fpPant,
                "Se mostraron %d movimientos bancarios en la lista.\n\n",
                cant);
    }


    fprintf(fpPant, "Eliminando y mostrando los movimientos de CtaCte.\n");
    cantElim = eliminarMostrarYMostrarSubTot(&lista, fpPant,
                                             compararMovim,
                                             esCtaCte002,
                                             acumularMoviSaldo,
                                             mostrarMovim,
                                             mostrarTotal);
//    cantElim = eliminarMostrarYMostrarSubTot_MIO(&lista, fpPant,
//                                                 compararMovim_MIO,
//                                                 esCtaCte002_MIO,
//                                                 acumularMoviSaldo_MIO,
//                                                 mostrarMovim_MIO,
//                                                 mostrarTotal_MIO);
//    fprintf(fpPant, "Se eliminaron %d nodos de CtaCte.\n\n", cantElim);

    fprintf(fpPant, "Vaciando la lista y mostrando las cuentas remanentes.\n");
//    cant = vaciarListaYMostrar(&lista, mostrarMovim, fpPant);
    cant = vaciarListaYMostrar_MIO(&lista, mostrarMovim_MIO, fpPant);
    fprintf(fpPant, "Se eliminaron y mostraron %d nodos de la lista", cant);

    if(fpPant != stdout && fpPant != stderr && fpPant != NULL)
    {
        fclose(fpPant);
        system("start notepad pantalla.txt");
    }
    return 0;
}

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

