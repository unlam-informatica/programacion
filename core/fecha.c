#include "fecha.h"

static const int dias_por_mes[2][13] = {
    {0,31,28,31,30,31,30,31,31,30,31,30,31},
    {0,31,29,31,30,31,30,31,31,30,31,30,31}
};

static const int dias_acumulados[2][13] = {
    {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365},
    {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366}
};

int es_fecha_valida(Fecha *fecha) {
    return fecha->anio >= 1600 &&
           (fecha->mes >= 1 && fecha->mes <=12) &&
           (fecha->dia >= 1 && fecha->dia <= dias_por_mes[es_bisiesto(fecha->anio)][(fecha->mes)]);
}

/**
 * Valida si el año es bisiesto.
 * Retorna 1 si el año es bisiesto, de lo contrario retorna 0;
 */
int es_bisiesto(int anio) {
    return (anio % 400 == 0 || (anio % 4 == 0 && anio % 100 != 0)) ? 1 : 0;
}

/**
 * Calcula el día siguiente a la fecha indicada.
 */
Fecha dia_siguiente(Fecha *fecha) {
    int bisiesto = es_bisiesto(fecha->anio);

    Fecha nueva_fecha;
    nueva_fecha.dia = ((fecha->dia + 1) > dias_por_mes[bisiesto][fecha->mes]) ? 1 : fecha->dia + 1;
    nueva_fecha.mes = nueva_fecha.dia == 1 ? fecha->mes + 1 > 12 ? 1 : fecha->mes + 1 : fecha->mes;
    nueva_fecha.anio = ((fecha->mes + 1)>12) ?  fecha->anio + 1 : fecha->anio;

    return nueva_fecha;
}

/**
    Suma la cantidad de días indicados a f1 y pone el resultado en f2.
*/
Fecha sumar_dias(Fecha *f1, int dias) {
    Fecha nueva_fecha = {f1->dia, f1->mes, f1->anio};
    while(dias > 0) {
        int dias_del_mes = dias_por_mes[es_bisiesto(nueva_fecha.anio)][nueva_fecha.mes];
        if((nueva_fecha.dia + dias) > dias_del_mes) {
            int diferencia_fin_mes = dias_del_mes - nueva_fecha.dia;
            nueva_fecha.dia = dias_del_mes;
            // Hacemos uso de la función día_siguiente para poder calcular automaticamente el mes y año siguiente.
            nueva_fecha = dia_siguiente(&nueva_fecha);
            dias = dias - diferencia_fin_mes - 1; // restamos 1 más debido al uso de la función dia_siguiente.
        } else {
            nueva_fecha.dia += dias;
            dias -= dias;
        }
    }
    return nueva_fecha;
}

/**
    Resta la cantidad de días indicados a f1 y pone el resultado en f2.
*/
Fecha restar_dias(Fecha *f1, int dias) {
//    Fecha nueva_fecha = {f1->dia, f1->mes, f1->anio};
//    while(dias > 0) {
//        int dias_del_mes = dias_por_mes[es_bisiesto(nueva_fecha.anio)][nueva_fecha.mes];
//        if((nueva_fecha.dia + dias) > dias_del_mes) {
//            int diferencia_fin_mes = dias_del_mes - nueva_fecha.dia;
//            nueva_fecha.dia = dias_del_mes;
//            // Hacemos uso de la función día_siguiente para poder calcular automaticamente el mes y año siguiente.
//            nueva_fecha = dia_siguiente(&nueva_fecha);
//            dias = dias - diferencia_fin_mes - 1; // restamos 1 más debido al uso de la función dia_siguiente.
//        } else {
//            nueva_fecha.dia += dias;
//            dias -= dias;
//        }
//    }
    return (Fecha){1, 2, 1991};
}

/**
    Valida si una fecha es menor que la otra. Retorna:
    1 si f1 es menor que f2
    0 si f1 no es menor que f2
    Tener que encuenta que no valida si las fechas son iguales.
*/
int es_antes(Fecha *f1, Fecha *f2) {
    int es_menor = 0;
    if(f1->anio < f2->anio){
        es_menor = 1;
    } else if(f1->anio == f2->anio){
        if(f1->mes < f2->mes){
            es_menor = 1;
        } else if(f1->mes == f2->mes){
            es_menor = f1->dia < f2->dia ? 1 : 0;
        } else {
            es_menor = 0;
        }
    } else {
        es_menor = 0;
    }
    return es_menor;
}

int es_igual(Fecha *f1, Fecha *f2) {
    return f1->anio == f2->anio && f1->mes == f2->mes && f1->dia == f2->dia;
}

/**
    Calcula cuantos días tiene el año.
*/
int dias_anio(int anio) {
    return 365 + es_bisiesto(anio);
}

/**
    Dentro del año de la fecha indicada, retorna la cantidad de días transcurridos desde el 01/01 hasta el día y mes de la fecha.
*/
int dias_transcurridos_anio(Fecha *f) {
    return dias_acumulados[es_bisiesto(f->anio)][f->mes - 1] + f->dia;
};

/**
    Calcula la cantidad de días transcurridos entre dos fechas.
*/
int dif_dias(Fecha *f1, Fecha *f2) {
    Fecha *aux;
    // Si f1 es una fecha anterior a f2, intercambiamos punteros para poder restar las fechas.
    if(es_antes(f2, f1)) {
        aux = f1;
        f1 = f2;
        f2 = aux;
    }

    int dif = 0;
    for(int i=f1->anio; i <= f2->anio; i++) {
        //  El año de f1 es menor que el de f2. Sumo los días que faltan hasta fin de año.
        if(i == f1->anio && i < f2->anio) {
            dif += dias_anio(i) - dias_transcurridos_anio(f1);
        }
        //  Las dos fechas son el mismo año. Sumo la diferencia entre los días transcurridos de ambas fechas.
        else if(i == f1->anio && i == f2->anio) {
            dif += dias_transcurridos_anio(f2) - dias_transcurridos_anio(f1);
        }
        //  Me encuentro en un año intermedio entre las dos fechas. Sumo los días que tiene ese año.
        else if (i != f1->anio && i != f2->anio) {
            dif += dias_anio(i);
        } else {
            //  Me encuentro en f2. Calculo los dias que transcurrieron desde inicio de año hasta f2.
            dif += dias_transcurridos_anio(f2);
        }
    }
    return dif;
}

Fecha parsear_fecha(char *fecha) {
    return (Fecha) {
        .dia=1, .mes=1, .anio=1600
    };
}
