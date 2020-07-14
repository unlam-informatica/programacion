#ifndef TP1_EJ13_H_INCLUDED
#define TP1_EJ13_H_INCLUDED

typedef struct {
    char apellido[30];
    char nombre[30];
    unsigned int dni;
    double sueldo;
} Empleado;

typedef struct {
    char apellido[30];
    char nombre[30];
    unsigned int dni;
    float promedio;
} Estudiante;

int tp2_ej13();

#endif // TP1_EJ13_H_INCLUDED
