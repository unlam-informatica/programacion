#include <stdio.h>
#include "../../core/fecha.h"

#include "tp1_ej18.h"

int tp1_ej18() {
    int dif = 0;

    puts("Fecha 1\t\tFecha 2\t\tDiferencia en dias\t\tEs correcto?");

    // el mismo dia
    dif = dif_dias(&((Fecha) {
        17,04,2020
    }), (&(Fecha) {
        17,04,2020
    }));
    printf("17-04-2020\t17-04-2020\t%d\t\t\t\t%s\n", dif, dif == 0 ? "Si" : "No");


    // un dia antes
    dif = dif_dias(&(Fecha) {
        16,04,2020
    }, &(Fecha) {
        17,04,2020
    });
    printf("16-04-2020\t17-04-2020\t%d\t\t\t\t%s\n", dif, dif == 1 ? "Si" : "No");


    // un dia despues
    dif = dif_dias(&(Fecha) {
        18,04,2020
    }, &(Fecha) {
        17,04,2020
    });
    printf("18-04-2020\t17-04-2020\t%d\t\t\t\t%s\n", dif, dif == 1 ? "Si" : "No");


    // mismo dia un mes antes
    dif = dif_dias(&(Fecha) {
        17,03,2020
    }, &(Fecha) {
        17,04,2020
    });
    printf("17-03-2020\t17-04-2020\t%d\t\t\t\t%s\n", dif, dif == 31 ? "Si" : "No");

    // mismo dia un mes despues
    dif = dif_dias(&(Fecha) {
        17,05,2020
    }, &(Fecha) {
        17,04,2020
    });
    printf("17-05-2020\t17-04-2020\t%d\t\t\t\t%s\n", dif, dif == 30 ? "Si" : "No");


    // un dia y un mes despues
    dif = dif_dias(&(Fecha) {
        18,05,2020
    }, &(Fecha) {
        17,04,2020
    });
    printf("18-04-2020\t17-04-2020\t%d\t\t\t\t%s\n", dif, dif == 31 ? "Si" : "No");


    // un dia y un mes antes
    dif = dif_dias(&(Fecha) {
        16,03,2020
    }, &(Fecha) {
        17,04,2020
    });
    printf("16-03-2020\t17-04-2020\t%d\t\t\t\t%s\n", dif, dif == 32 ? "Si" : "No");


    // un dia, un mes y un año antes
    dif = dif_dias(&(Fecha) {
        16,03,2019
    }, &(Fecha) {
        17,04,2020
    });
    printf("16-03-2019\t17-04-2020\t%d\t\t\t\t%s\n", dif, dif == 398 ? "Si" : "No");


    // un dia, un mes y un año después
    dif = dif_dias(&(Fecha) {
        18,05,2021
    }, &(Fecha) {
        17,04,2020
    });
    printf("18-05-2021\t17-04-2020\t%d\t\t\t\t%s\n", dif, dif == 396 ? "Si" : "No");


    puts("\n\n\n\n\n\n");
    return 1;
}
