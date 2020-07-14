#ifndef TP2_EJ9_H_INCLUDED
#define TP2_EJ9_H_INCLUDED

/**
    Escriba un programa que genere un archivo de texto ("datos.txt") a partir del ingreso por teclado de números enteros,
    de modo que en cada línea de texto haya una cantidad variable de cadenas de caracteres que representen tales números.
    En el archivo debe haber como mínimo la representación de un entero y como máximo de siete.
    La separación entre estas cadenas que representan números debe ser de al menos un carácter espacio (' ') o a lo sumo cinco,
     de modo que queden alineados por la derecha al leer el contenido del archivo con un procesador de texto como el ‘Notepad’ o ‘Bloc de Notas’.
    Ingrese los enteros con una variable short int (note que el rango de las mismas pertenece al intervalo [-32768, 32767]).
    Vea e interprete qué sucede cuando ingresa números fuera de ese rango.

    Note que:
    - los caracteres de separación sólo están entre números
    - en el archivo debe haber al menos una línea con un número y otra con siete
    Utilice el generador de números pseudo aleatorios para determinar cuántos números se almacenan por línea de texto,
     y además para que determine cuántas líneas se almacenarán una vez cumplida la condición de una línea con un número y otra con siete.
*/
int tp2_ej9();

#endif // TP2_EJ9_H_INCLUDED
