#include "fecha.h"

const int dias_por_mes[][13] = {{0,31,28,31,30,31,30,31,31,30,31,30,31},{0,31,29,31,30,31,30,31,31,30,31,30,31}};

int es_fecha_valida(Fecha *fecha) {
    return fecha->anio >= 1600 &&
           (fecha->mes >= 1 && fecha->mes <=12) &&
           (fecha->dia >= 1 && fecha->dia <= dias_por_mes[es_bisiesto(fecha->anio)][(fecha->mes)]);
}

int es_bisiesto(int anio) {
    return (anio % 400 == 0 || (anio % 4 == 0 && anio % 100 != 0)) ? 1 : 0;
}

Fecha dia_siguiente(Fecha *fecha) {
    int bisiesto = es_bisiesto(fecha->anio);

    Fecha nueva_fecha;
    nueva_fecha.dia = ((fecha->dia + 1) > dias_por_mes[bisiesto][fecha->mes]) ? 1 : fecha->dia + 1;
    nueva_fecha.mes = nueva_fecha.dia == 1 ? fecha->mes + 1 > 12 ? 1 : fecha->mes + 1 : fecha->mes;
    nueva_fecha.anio = ((fecha->mes + 1)>12) ?  fecha->anio + 1 : fecha->anio;

    return nueva_fecha;
}

Fecha sumar_dias(Fecha *fecha, int dias) {
    Fecha nueva_fecha = {fecha->dia, fecha->mes, fecha->anio};
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

Fecha parsear_fecha(char *fecha) {
    return (Fecha) {
        .dia=1, .mes=1, .anio=1600
    };
}
