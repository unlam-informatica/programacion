# Programación 2020 - UNLaM

- [Programación 2020 - UNLaM](#programacion-2020---unlam)
  * [Cadenas](#cadenas)
    + [`sprintf` - Escritura formateada](#sprintf---escritura-formateada)
    + [`sscanf` - Lectura formateada](#sscanf---lectura-formateada)
    + [`strcmp` - Comparar dos cadenas](#strcmp---comparar-dos-cadenas)
    + [`strrchr` - Buscar último caracter en una cadena](#strrchr---buscar-ultimo-caracter-en-una-cadena)
    + [`strncpy` - Copiar n caracteres de una cadena a otra](#strncpy---copiar-n-caracteres-de-una-cadena-a-otra)
  * [Archivos](#archivos)
      - [`fopen` - Abrir archivo](#fopen---abrir-archivo)
      - [`rewind` - Volver al inicio de archivo](#rewind---volver-al-inicio-de-archivo)
      - [`feof` - Validación de fin de archivo](#feof---validacion-de-fin-de-archivo)
      - [`ftell` - Obtener posición actual](#ftell---obtener-posicion-actual)
      - [`fseek` - Reposicionarse en el archivo](#fseek---reposicionarse-en-el-archivo)
      - [`fclose` - Cerrar archivo](#fclose---cerrar-archivo)
      - [`remove` - Eliminar archivo](#remove---eliminar-archivo)
    + [Archivos binarios](#archivos-binarios)
      - [`fread` - Lectura](#fread---lectura)
      - [`fwrite` - Escritura](#fwrite---escritura)
    + [Archivos de texto](#archivos-de-texto)
      - [`fgets` - Lectura de archivo a string](#fgets---lectura-de-archivo-a-string)
      - [`fscanf` - Lectura de archivo a variables](#fscanf---lectura-de-archivo-a-variables)
      - [`fprintf` - Escritura de string con variables](#fprintf---escritura-de-string-con-variables)
      - [`fputc` - Escritura de string sin variables](#fputc---escritura-de-string-sin-variables)
      - [`fputs` - Escritura de string sin variables](#fputs---escritura-de-string-sin-variables)
    + [Organización de los datos en archivos de texto](#organizacion-de-los-datos-en-archivos-de-texto)
      - [Campos de longitud variable](#campos-de-longitud-variable)
      - [Campos de longitud fija](#campos-de-longitud-fija)
    + [Notas sobre archivos](#notas-sobre-archivos)
  * [Metodos de ordenamiento](#metodos-de-ordenamiento)
    + [Metodo de burbujeo](#metodo-de-burbujeo)
    + [Metodo de selección](#metodo-de-seleccion)
    + [Metodo de inserción](#metodo-de-insercion)
  * [Otras notas](#otras-notas)
      - [Uso de `srand`](#uso-de-srand)
      - [Como definir una función que acepta otra por parámetro](#como-definir-una-funcion-que-acepta-otra-por-parametro)
    + [Intercambiar dos variables de cualquier tipo](#intercambiar-dos-variables-de-cualquier-tipo)



## Cadenas
Especificadores de formato de para `printf`, `sprintf`, `fprintf`

```
%[flags][width][.precision][length]specifier
```

- `[flags]`: Alinea texto a la izquierda con el parametro indicado. Se utiliza `-` para alinear texto a la izquierda y `0` para completar el numero con `0` a la izquierda. En caso de no querer alinear a izquierda, no lleva nada.
- `[width]`: tamaño de campo en que se muestra la cadena. Si es mayor que el tamaño de la cadena quedará alineado a derecha, salvo que esté indicado `[flags]` como `-`.
- `[.precision]`: máxima cantidad de caracteres a mostrar.
Los dos enteros para tamaño de campo y la cantidad máxima son opcionales e independientes entre sí. Se pueden reemplazar en la cadena de conversión de formato por (\*), con lo que deberá haber una constante literal entera o una variable entera, por cada asterisco que se indique, como argumentos para el printf.
- `specifier`: Especificador del tipo de datos como ser `d`, `x`, `c`, `s`

ver http://www.cplusplus.com/reference/cstdio/printf/ para mas detalles.

### `sprintf` - Escritura formateada
```c
int sprintf(char * str, const char * format, ...);
```
Cumple la misma funcion que `printf` (se utiliza de la misma manera), pero en vez de imprimir en pantalla, copia el texto de salida a la variable `str`.

`str` debe ser capaz de almacenar la cadena resultante.

Al final de la cadena, se añade un caracter de terminación `\0`.

### `sscanf` - Lectura formateada
```c
int sscanf(const char *s, const char *format, ...);
```
Cumple la misma funcion que `scanf` (se utiliza de la misma manera), pero en vez de obtener los valores por teclado, los obtiene a partir de `s`.

Lee valores de la cadena `s` y los guarda en cada una de las variables referenciadas por format.

### `strcmp` - Comparar dos cadenas
```c
int strcmp ( const char * str1, const char * str2 );
```
Compara `str1` con `str2` y retorna:

* `<0` str es menor que str2
* `0`  si son iguales
* `>0` str es menor que str2

### `strrchr` - Buscar último caracter en una cadena
```c
char *strrchr(char *str, int character);
```
Retorna un puntero a la última ocurrencia de `character` en la cadena `str`.

El caracter de fin de cadena `\0` tambien se considera parte de la cadena por lo que se puede utilizar esta funcion para obtener un puntero al final de la cadena.

### `strncpy` - Copiar n caracteres de una cadena a otra
```c
char *strncpy(char *destination, const char *source, size_t n);
```
Copia los primeros `n` caracteres de `source` en `destination`.

Si se halla el final de linea en source antes de leer `n` caracteres, la cadena de destino se completa con ceros hasta un total de `n` caracteres.

**Cuidado!**: Si la cadena origen es mas larga que la cadena destino, al finalizar la copia de las cadenas no se añade el terminador de linea `\0`.

## Archivos

#### `fopen` - Abrir archivo
```c
FILE * fopen(const char *filename, const char *mode);
```

* `filename`: Nombre del archivo a abrir.
 
* `mode:` Modo de apertura.

| Modo de acceso | Descripción |
| :------------: | ----------- |
| "r" |	Abre un archivo para lectura y se ubica al inicio del mismo. Si el archivo no existe, retorna NULL. |
| "w" |	Crea un archivo para escritura. Si el archivo ya existe, lo pisa crea uno nuevo vacío.
| "a" |	Abre un archivo para agregar datos al final del mismo. Si el archivo existe, el puntero se ubica al final del archivo. Si no existe, retorna NULL. |
| "r+" | Abre un archivo para lectura y escritura. El puntero se ubica al inicio del archivo. Si el archivo no existe, retorna NULL. |
| "w+" | Crea un archivo para lectura y escritura. El puntero se ubica al inicio del archivo. Si el archivo ya existe lo pisa y crea uno nuevo vacío. |
| "a+" | Abre un archivo para lectura y escritura. El puntero se ubica al final del archivo. Si el archivo no existe, lo crea. Las operaciones de reposicionamiento (`fseek`, `fsetpos`, `rewind`) afectan a la siguiente operación de lectura, pero las operaciones de escritura, mueven la posición del puntero de vuelta al final del archivo.

Los especificadores de modo por defecto abren los archivos como archivos de texto sin embargo es buena practica especificar el tipo de archivo. Los dos tipos de archivos disponibles son texto `"t"` y binario `"b"`. La `"t"` y `"b"` se pueden añadir antes o después del `+`. Por ejemplo `"rbb"` y `"r+b"` son válidos.

#### `rewind` - Volver al inicio de archivo
#### 
```c
void rewind(FILE * stream );
```

Vuelve el indicador de posición al inicio del archivo referenciado por `stream`.

#### `feof` - Validación de fin de archivo
```c
int feof(FILE *stream);
```
Retorna un valor distinto de cero si el indicador de fin de archivo asociado con el stream es verdadero.

Este indicador generalmente se setea mediante una operación previa como `fread` y `fwrite`.

`feof(FILE *stream);` retorna fin de archivo una vez que realizo un intento de lectura fallido. Por lo que primero tengo que realizar una lectura inicial y luego verificar por fin de archivo. Por ejemplo:
```c
FILE *pf = fopen("archivo.bin", "rb");
fread(&num, sizeof(int), 1, pf);
while(!feof(pf)){
	printf("%d\n", num);
	fread(&num, sizeof(int), 1, pf);
}
fclose(pf);
```

#### `ftell` - Obtener posición actual
```c
long int ftell(FILE *stream);
```
Retorna el valor actual del indicador de posición para el archivo apuntado por `stream`.

Para archivos binarios, el valor retornado indica la cantida de bytes de desplazamiento desde el inicio del archivo.

Para archivos de texto no es representativo pero puede usarse como referencia para luego utilizar `fseek` y volver al mismo punto.

#### `fseek` - Reposicionarse en el archivo
```c
int fseek(FILE *stream, long int offset, int origin);
```
Setea el indicador de posición del archivo referenciado por `stream` a la posición indicada mediante un desplazamiento `offset` a partir de un punto de partida `origin`.

La variable `origin` puede tener uno de los siguientes valores:

|Constante|Descripción|
|---------|-----------|
|SEEK_SET|Inicio del archivo|
|SEEK_CUR|Posición actual del puntero `stream`|
|SEEK_END|Fin del archivo|

#### `fclose` - Cerrar archivo
```c
int fclose( FILE *stream);
```
Cierra un archivo y desasocia el stream. Todo el contenido que se encuentre en el stream es grabado al archivo antes de cerrarlo.

#### `remove` - Eliminar archivo
```c
int remove(const char *filename );
```
Elimina el archivo en la dirección indicada por `filename`. Generalmente, la dirección es relativa a la carpeta base del proyecto.


### Archivos binarios
#### `fread` - Lectura
```c
size_t fread(void *ptr, size_t size, size_t count, FILE *stream);
```

- `ptr`: Puntero a una variable donde serán escritos los datos leídos del archivo. 

- `size`: Cantidad de bytes a leer del archivo.

- `count`: Cantidad de elementos de tamaño `size` que se deben a leer.

- `stream`: Puntero al archivo.

La posición del puntero avanza la cantidad de bytes indicadas por `fread`.

#### `fwrite` - Escritura
```c
size_t fwrite(const void *ptr, size_t size, size_t count, FILE *stream);
```

- `ptr`: Puntero a una variable de donde serán leídos los datos a escribir al archivo.

- `size`: Cantidad de bytes a escribir en el archivo.

- `count`: Cantidad de elementos de tamaño `size` que se deben a escribir.

- `stream`: Puntero al archivo.

### Archivos de texto
#### `fgets` - Lectura de archivo a string
```c
char* fgets(char *str, int num, FILE *stream);
```
Lee caracteres del archivo y los copia a `str` hasta que se hayan leído `num - 1` caracteres o se encuentre un caracter de fin de linea `\n` o fin de archivo `\0`. Añade el caracter `\0` a continuación del ultimo caracter copiado.

#### `fscanf` - Lectura de archivo a variables
```c
int fscanf(FILE *stream, const char *format, ...);
```
Permite realizar la lectura desde el archivo de texto apuntado por `stream` de acuerdo al formato especificado en `format` y asigna los valores a las variables especificadas.

#### `fprintf` - Escritura de string con variables
```c
int fprintf(FILE *stream, const char *format, ... );
```
Escribe en el archivo apuntado por `stream` la cadena de caracteres apuntada por `format`. La cadena indicada en `format` pueden incluir _especificadores de formato_ de la misma manera que utilizando `printf`.

#### `fputc` - Escritura de string sin variables
```c
int fputc(int character, FILE *stream);
```
Copia el caracter `character` al archivo apuntado por `stream` y avanza una posición.

#### `fputs` - Escritura de string sin variables
```c
int fputs(const char *str, FILE *stream);
```
Copia la cadena de caracteres apuntada por `str` hasta encontrar el caracter de fin de texto `\0` al archivo apuntado por `stream`. El caracter de finalización `\0` no es copiado.

### Organización de los datos en archivos de texto
Tenemos dos formas de orgnizar los archivos de texto: campos de longitud variable y campos de longitud fija. Al decir campos nos referimos a las diferentes unidades de datos que completan cada registro o fila del archivo.

#### Campos de longitud variable
Se define un caracter que separa cada uno de los campos del registro. Por ejemplo utilizando `|` como separador de campos:

```text
44444444|Persona Cuatro|A|1/4/2004|44000.44 
22222222|Persona Dos|B|1/2/2002|22000.25
33333333|Persona Tres|B|1/3/2003|33000.32
```

**código:** [txt_longitud_variable](https://gist.github.com/marcos-rios/edc48c8d4138ba18fb450694b9d5a55e)

#### Campos de longitud fija
La longitud de cada campo se define de antemano y se respeta para todos los registros aunque sobre espacio sin utilizar. Por ejemplo si se define el campo `nombre` con 30 caracteres y un campo definido ocupa 14, se rellena con espacios al final.

```
44444444Persona Cuatro                        A01042004 44000.44
22222222Persona Dos                           B01022002 22000.25
33333333Persona Tres                          B01032003 33000.32
55555555Persona Cinco mil treinta y dos       A01052005 55000.50
01111111Persona Uno                           C01012001111000.10
```

Cuando pase de txt fijo a binario, tengo que eliminar los espacios que tengo de más al asignarlo a la variable usando `strtrim`
**Nota:** Una de los beneficios de los archivos de longitud fija es que, si estan ordenados, puedo realizar una búsqueda binaria dentro del mismo archivo ya que cada uno de los registros siempre va a ocupar el mismo numero de bytes. La desventaja es que obviamente, ocupa más espacio.

### Notas sobre archivos
Si realizo un cambio de operación, por ejemplo realizo un `fwrite` y luego quiero realizar un `fread`, entre las dos operaciones, tengo que realizar un `fseek` para que se posicione correctamente el indicador de posición. Por ejemplo:

```c
fread(pf, sizeof(int), 1, &num);
fseek(pf, -sizeof(num), SEEK_CUR);
fwrite(pf, sizeof(int), 1, &num);
fseek(pf, 0L, SEEK_CUR);
fread(pf, sizeof(int), 1, &num);
```

## Metodos de ordenamiento
### Metodo de burbujeo

```c
void ordenar_burbujeo(int * v, int cant_elem) {
  int i = 1, j;
  int huboIntercambios = 1;
  while (huboIntercambios && i < cant_elem) {
    huboIntercambios = 0;
    for (j = 0; j < cant_elem– i; j++) {
      if (v[j] > v[j + 1]) {
        intercambiar( & v[j], & v[j + 1]);
        huboIntercambios = 1;
      }
    }
    i++;
  }
}
``` 

### Metodo de selección
```c
void ordenar_seleccion(int *v, int cant_elem) {
  int m;
  for (int i = 0; i < cant_elem - 1; i++) {
    m = buscar_menor(v, i, cant_elem - 1);
    if (m != i)
      intercambiar( & v[m], & v[i]);
  }
}

int buscar_menor(int * v, int desde, int hasta) {
  int m = desde;
  for (int j = desde + 1; j <= hasta; j++) {
    if (v[j] < v[m])
      m = j;
  }
  return m;
}
```

### Metodo de inserción
Se presupone que el array donde se van a insertan los elementos esta ordenado. Cada elemento a insertar se inserta en la posición que le corresponde según su orden.
```c
void ordena_insercion(int * v, int cant_elem) {
  int j;
  int elemento_a_insertar;
  for (int i = 1; i < cant_elem; i++) {
    elemento_a_insertar = v[i];
    j = i - 1;
    while (j >= 0 && elemento_a_insertar < v[j]) {
      v[j + 1] = v[j];
      j--;
    }
    v[j + 1] = elemento_a_insertar;
  }
}
```

## Otras notas

`sizeof(array)` retorna el tamaño en bytes del array referenciado.

`switch` acepta strings como parametro

#### Uso de `srand`
```c
/**
	Inicialización y uso de srand
*/
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

srand (time(NULL));
printf("Numero aleatorio: %d\n", rand() % 100);
```

#### Como definir una función que acepta otra por parámetro
Para definir una función que recibe otra funcion por parametro, tengo que definirla de la siguiente manera:
```c
/**
	defino un tipo de dato que apunta a una función.
	Define el mismo tipo de dato para los parametros que cmp.
*/
typedef int (*Cmp)(const void *v1, const void *v2);
/**
	Compara v1 y v2. Retorna un numero negativo si v1 es menor a v2.
*/

int cmp(const void *v1, const void *v2);


/**
	Recibe una función de comparación por parametro.
*/
void buscar_menor(int desde, int hasta, Cmp cmp);
```

### Intercambiar dos variables de cualquier tipo
```c
#include <string.h>

void intercambiar(void *a, void *b, size_t tam){
	char aux[tam];
	memcpy(aux, a, tam);
	memcpy(a, b, tam);
	memcpy(b, aux, tam);
}
```