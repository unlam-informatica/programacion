/**
    Se dispone de dos archivos binarios: <"empleados"> y <"estudiantes">.
    Cada registro del primer archivo contiene los campos:
    - <dni>, <apellido>, <nombre> y <sueldo>,
    en tanto que los del segundo:
    - <dni>, <apellido>, <nombre> y <promedio>.
    Ambos archivos están ordenados alfabéticamente por <apellido> / <nombre> /<dni>.
    Ambos archivos deben ser leídos sólo una vez, y no deben ser almacenados en arrays.
    El sueldo es double y el promedio es float.
    Escriba un programa que, leyendo ambos archivos, actualice el sueldo de aquellos empleados
    que tengan un registro de estudiante con un promedio superior a 7, en un 7,28%
*/

#include <stdio.h>
#include <string.h>
#include "tp2_ej13.h"

#define TODO_OK 0
#define ERROR_ARCH 1

#define TAM_VEC_ESTUDIANTES 3
#define ARCHIVO_ESTUDIANTES "tp2/ej13/estudiantes"

#define TAM_VEC_EMPLEADOS 5
#define PROCENTAJE_AUMENTO 1.728
#define ARCHIVO_EMPLEADOS "tp2/ej13/empleados"
#define ARCHIVO_EMPLEADOS_ACT "tp2/ej13/empleados.tmp"

void crear_archivos();
void actualizar_empleados();
void mostrar_empleados();

int tp2_ej13() {
    crear_archivos();
    actualizar_empleados();
    mostrar_empleados();

    return 0;
}

void actualizar_empleados() {
    FILE *pf_emp = fopen(ARCHIVO_EMPLEADOS, "r+b");
    FILE *pf_est = fopen(ARCHIVO_ESTUDIANTES, "rb");
    FILE *pf_act = fopen(ARCHIVO_EMPLEADOS_ACT, "wb");

    if(!pf_emp){
        printf("Ocurrio un error al abrir pf_emp");
        return;
    }
    if(!pf_est){
        printf("Ocurrio un error al abrir pf_est");
        return;
    }
    if(!pf_act) {
        printf("Ocurrio un error al crear pf_act");
        return;
    }

    Empleado empleado;
    Estudiante estudiante;

    fread(&estudiante, sizeof(Estudiante), 1, pf_est);
    fread(&empleado, sizeof(Empleado), 1, pf_emp);
    while(!feof(pf_emp) && !feof(pf_est)) {
        int cmp_apellido = strcmp(empleado.apellido, estudiante.apellido);
        int cmp_nombre = strcmp(empleado.nombre, estudiante.nombre);

        if(cmp_apellido <= 0 && cmp_nombre <= 0 && empleado.dni != estudiante.dni) {
            fwrite(&empleado, sizeof(Empleado), 1, pf_act);
            fread(&empleado, sizeof(Empleado), 1, pf_emp);
        } else if(empleado.dni == estudiante.dni) {
            if(estudiante.promedio > 7) {
                empleado.sueldo = (empleado.sueldo * PROCENTAJE_AUMENTO);
                printf("Actualizando sueldo de empleado %s %s a: %.2f\n", empleado.apellido, empleado.nombre, empleado.sueldo);
            }
            fwrite(&empleado, sizeof(Empleado), 1, pf_act);
            fread(&empleado, sizeof(Empleado), 1, pf_emp);
            fread(&estudiante, sizeof(Estudiante), 1, pf_est);
        } else {
            // Suponemos que no debemos agregar estudiantes que no figuren en el archivo de empleado
            // por lo que solo avanzamos en el archivo de estudiantes.
            fread(&estudiante, sizeof(Estudiante), 1, pf_est);
        }
    }
    while(!feof(pf_emp)) {
        fwrite(&empleado, sizeof(Empleado), 1, pf_act);
        fread(&empleado, sizeof(Empleado), 1, pf_emp);
    }

    fclose(pf_est);
    fclose(pf_emp);
    fclose(pf_act);
}

void mostrar_empleados() {
    FILE *pf_act = fopen(ARCHIVO_EMPLEADOS_ACT, "rb");
    Empleado empleado;
    while(fread(&empleado, sizeof(Empleado), 1, pf_act)){
        printf("%s %s, DNI: %8d, Salario: %7.2f\n", empleado.apellido, empleado.nombre, empleado.dni, empleado.sueldo);
    }
    fclose(pf_act);
}

void crear_archivos() {
    FILE *pfemp = fopen(ARCHIVO_EMPLEADOS, "wb");
    FILE *pfest = fopen(ARCHIVO_ESTUDIANTES, "wb");

    Empleado emp_array[TAM_VEC_EMPLEADOS] = {
        {"Gonzalez", "Matias", 11233173, 12000},
        {"Perez", "Alberto", 18293123, 10000},
        {"Perez", "Juan", 32293673, 11000},
        {"Tibaudo", "Jose", 25978123, 23000}
    };
    Estudiante est_array[TAM_VEC_ESTUDIANTES] = {
        {"Gonzalez", "Matias", 11233173, 5},
        {"Perez", "Juan", 32293673, 7},
        {"Tibaudo", "Jose", 25978123, 7.5}
    };

    fwrite(emp_array, sizeof(Empleado), TAM_VEC_EMPLEADOS, pfemp);
    fwrite(est_array, sizeof(Estudiante), TAM_VEC_ESTUDIANTES, pfest);

    fclose(pfemp);
    fclose(pfest);
}
