#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

typedef struct {
    int dia, mes, anio;
} Fecha;

int es_fecha_valida(Fecha *fecha);

int es_bisiesto(int anio);

Fecha parsear_fecha(char *fecha);

Fecha dia_siguiente(Fecha *fecha);

Fecha sumar_dias(Fecha *fecha, int dias_a_sumar);

#endif // FECHA_H_INCLUDED
