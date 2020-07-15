cmake_minimum_required(VERSION 3.16)
project(programacion_unlam)

set(CMAKE_CXX_STANDARD 14)

include_directories(guia/core)
include_directories(guia/tp1/ej1)
include_directories(guia/tp1/ej14)
include_directories(guia/tp1/ej15)
include_directories(guia/tp1/ej16)
include_directories(guia/tp1/ej17)
include_directories(guia/tp1/ej18)
include_directories(guia/tp1/ej2)
include_directories(guia/tp1/ej22)
include_directories(guia/tp1/ej3)
include_directories(guia/tp1/ej4)
include_directories(guia/tp2/ej1)
include_directories(guia/tp2/ej13)
include_directories(guia/tp2/ej9)
include_directories(parciales/ea1)
include_directories(parciales/ea2-c)
include_directories(parciales/ea2-cpp)
include_directories(parciales/ea2r-c)
include_directories(parciales/ea3-c)
include_directories(parciales/ea3-cpp)

add_executable(programacion_unlam
        guia/core/fecha.c
        guia/core/fecha.h
        guia/core/menu.c
        guia/core/menu.h
        guia/core/pila_dinamica.c
        guia/core/pila_dinamica.h
        guia/core/pila_estatica.c
        guia/core/pila_estatica.h
        guia/core/tp1.c
        guia/core/tp1.h
        guia/core/tp2.c
        guia/core/tp2.h
        guia/core/types.h
        guia/core/utils.c
        guia/core/utils.h
        guia/tp1/ej1/tp1_ej1.c
        guia/tp1/ej1/tp1_ej1.h
        guia/tp1/ej14/tp1_ej14.c
        guia/tp1/ej14/tp1_ej14.h
        guia/tp1/ej15/tp1_ej15.c
        guia/tp1/ej15/tp1_ej15.h
        guia/tp1/ej16/tp1_ej16.c
        guia/tp1/ej16/tp1_ej16.h
        guia/tp1/ej17/tp1_ej17.c
        guia/tp1/ej17/tp1_ej17.h
        guia/tp1/ej18/tp1_ej18.c
        guia/tp1/ej18/tp1_ej18.h
        guia/tp1/ej2/tp1_ej2.c
        guia/tp1/ej2/tp1_ej2.h
        guia/tp1/ej22/tp1_ej22.c
        guia/tp1/ej22/tp1_ej22.h
        guia/tp1/ej3/tp1_ej3.c
        guia/tp1/ej3/tp1_ej3.h
        guia/tp1/ej4/tp1_ej4.c
        guia/tp1/ej4/tp1_ej4.h
        guia/tp2/ej1/tp2_ej1.c
        guia/tp2/ej1/tp2_ej1.h
        guia/tp2/ej13/tp2_ej13.c
        guia/tp2/ej13/tp2_ej13.h
        guia/tp2/ej9/tp2_ej9.c
        guia/tp2/ej9/tp2_ej9.h
        guia/main.c
#        parciales/ea1/funciones.c
#        parciales/ea1/funciones.h
#        parciales/ea1/main.c
#        parciales/ea1/main.h
#        parciales/ea2-c/funciones.c
#        parciales/ea2-c/funciones.h
#        parciales/ea2-c/main.c
#        parciales/ea2-c/main.h
#        parciales/ea2-cpp/main.cpp
#        parciales/ea2-cpp/main.h
#        parciales/ea2-cpp/Prisma.cpp
#        parciales/ea2-cpp/Prisma.h
#        parciales/ea2r-c/funciones.c
#        parciales/ea2r-c/funciones.h
#        parciales/ea2r-c/main.c
#        parciales/ea2r-c/main.h
#        parciales/ea3-c/funciones.c
#        parciales/ea3-c/funciones.h
#        parciales/ea3-c/main.c
#        parciales/ea3-c/main.h
#        parciales/ea3-cpp/Cuadrado.cpp
#        parciales/ea3-cpp/Cuadrado.h
#        parciales/ea3-cpp/Figura.cpp
#        parciales/ea3-cpp/Figura.h
#        parciales/ea3-cpp/FiguraInvalidaException.h
#        parciales/ea3-cpp/main.cpp
#        parciales/ea3-cpp/Rectangulo.cpp
#        parciales/ea3-cpp/Rectangulo.h
#        parciales/ea3-cpp/Triangulo.cpp
#        parciales/ea3-cpp/Triangulo.h
        )

target_link_libraries(programacion_unlam m)