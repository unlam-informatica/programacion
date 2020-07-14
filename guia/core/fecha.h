#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

typedef struct {
    int dia, mes, anio;
} Fecha;

int es_fecha_valida(Fecha *f);

int es_bisiesto(int anio);

Fecha parsear_fecha(char *f);

Fecha dia_siguiente(Fecha *f);

Fecha sumar_dias(Fecha *f, int dias_a_sumar);

Fecha restar_dias(Fecha *f, int dias);

int es_antes(Fecha *f1, Fecha *f2);

int dias_transcurridos_anio(Fecha *f);

int dif_dias(Fecha *f1, Fecha *f2);

#endif // FECHA_H_INCLUDED
