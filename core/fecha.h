#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

typedef struct {
    int dia, mes, anio;
} Fecha;

int es_fecha_valida(Fecha *fecha);

int es_bisiesto(int anio);

Fecha parsear_fecha(char *fecha);

#endif // FECHA_H_INCLUDED
