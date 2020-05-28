# Programación 2020 - UNLaM
## Notas personales

### Cadenas
##### Escritura formateada `sprintf`
##### `int sprintf(char * str, const char * format, ...);`
Cumple la misma funcion que `printf` (se utiliza de la misma manera), pero en vez de imprimir en pantalla, copia el texto de salida a la variable `str`.

`str` debe ser capaz de almacenar la cadena resultante.

Al final de la cadena, se añade un caracter de terminación `\0`.

##### Lectura formateada `sscanf`
##### `int sscanf(const char *s, const char *format, ...);`
Cumple la misma funcion que `scanf` (se utiliza de la misma manera), pero en vez de obtener los valores por teclado, los obtiene a partir de `s`.

Lee valores de la cadena `s` y los guarda en cada una de las variables referenciadas por format.

##### `char *strrchr(char *str, int character);`
Retorna un puntero a la última ocurrencia de `character` en la cadena `str`.

El caracter de fin de cadena `\0` tambien se considera parte de la cadena por lo que se puede utilizar esta funcion para obtener un puntero al final de la cadena.

### Archivos
##### Abrir archivo
##### `FILE * fopen (const char *filename, const char *mode);`

> **filename:** Nombre del archivo a abrir.
> 
> **mode:** Modo de apertura.

| Modo de acceso | Descripción |
| :------------: | ----------- |
| "r" |	Abre un archivo para lectura y se ubica al inicio del mismo. Si el archivo no existe, retorna NULL. |
| "w" |	Crea un archivo para escritura. Si el archivo ya existe, lo pisa crea uno nuevo vacío.
| "a" |	Abre un archivo para agregar datos al final del mismo. Si el archivo existe, el puntero se ubica al final del archivo. Si no existe, retorna NULL. |
| "r+" | Abre un archivo para lectura y escritura. El puntero se ubica al inicio del archivo. Si el archivo no existe, retorna NULL. |
| "w+" | Crea un archivo para lectura y escritura. El puntero se ubica al inicio del archivo. Si el archivo ya existe lo pisa y crea uno nuevo vacío. |
| "a+" | Abre un archivo para lectura y escritura. El puntero se ubica al final del archivo. Si el archivo no existe, lo crea. Las operaciones de reposicionamiento (`fseek`, `fsetpos`, `rewind`) afectan a la siguiente operación de lectura, pero las operaciones de escritura, mueven la posición del puntero de vuelta al final del archivo.

Los especificadores de modo por defecto abren los archivos como archivos de texto sin embargo es buena practica especificar el tipo de archivo. Los dos tipos de archivos disponibles son texto `"t"` y binario `"b"`. La `"t"` y `"b"` se pueden añadir después o antes del `+`. Por ejemplo `"r+b"` y `"rb+"` son válidos.

##### Volver al inicio de archivo
##### `void rewind (FILE * stream );`
Vuelve el indicador de posición al inicio del archivo referenciado por `stream`.

##### Validación de fin de archivo
##### `int feof (FILE *stream);`
Retorna un valor distinto de cero si el indicador de fin de archivo asociado con el stream es verdadero.

Este indicador generalmente se setea mediante una operación previa como `fread` y `fwrite`.

##### Obtener posición actual
##### `long int ftell(FILE *stream);`
Retorna el valor actual del indicador de posición para el archivo apuntado por `stream`.

Para archivos binarios, el valor retornado indica la cantida de bytes de desplazamiento desde el inicio del archivo.

Para archivos de texto no es representativo pero puede usarse como referencia para luego utilizar `fseek` y volver al mismo punto.

##### Reposicionarse en el archivo
##### `int fseek(FILE * stream, long int offset, int origin);`
Setea el indicado de posición del archivo referenciado por `stream` a la posición indicada mediante un desplazamiento `offset` a partir de un punto de partida `origin`.

La variable `origin` puede tener uno de los siguientes valores:

|Constante|Descripción|
|---------|-----------|
|SEEK_SET|Inicio del archivo|
|SEEK_CUR|Posición actual del puntero `stream`|
|SEEK_END|Fin del archivo|

##### Cerrar archivo
##### `int fclose( FILE *stream);`
Cierra un archivo y desasocia el stream. Todo el contenido que se encuentre en el stream, es grabado al archivo antes de cerrarlo.

##### Eliminar archivo
##### `int remove(const char *filename );`
Elimina el archivo en la dirección indicada por `filename`. Generalmente, la dirección es relativa a la carpeta base del proyecto.


#### Archivos binarios

##### Lectura
##### `size_t fread(void *ptr, size_t size, size_t count, FILE *stream);`
> **ptr:** Puntero a una variable donde serán escritos los datos leídos del archivo.
> 
> **size:** Cantidad de bytes a leer del archivo.
> 
> **count:** Cantidad de elementos de tamaño `size` que se deben a leer.
> 
> **stream:** Puntero al archivo.

La posición del puntero avanza la cantidad de bytes indicadas por `fread`.

##### Escritura
##### `size_t fwrite(const void *ptr, size_t size, size_t count, FILE *stream);`

> **ptr:** Puntero a una variable de donde serán leídos los datos a escribir al archivo.
> 
> **size:** Cantidad de bytes a escribir en el archivo.
> 
> **count:** Cantidad de elementos de tamaño `size` que se deben a escribir.
> 
> **stream:** Puntero al archivo.

#### Archivos de texto

##### Lectura
##### `char *fgets(char *str, int num, FILE *stream);`
Lee caracteres del archivo y los copia a `str` hasta que se hayan leído `num - 1` caracteres o se encuentre un caracter de fin de linea `\n` o fin de archivo `\0`. Añade el caracter `\0` a continuación del ultimo caracter copiado.

##### `int fscanf(FILE *stream, const char *format, ...);`
Permite realizar la lectura desde el archivo de texto apuntado por `stream` de acuerdo al formato especificado en `format` y asigna los valores a las variables especificadas.

##### Escritura
##### `int fprintf(FILE *stream, const char *format, ... );`
Escribe en el archivo apuntaod por `stream` la cadena de caracteres apuntada por `format`. La cadena indicada en `format` pueden incluir _especificadores de formato_ de la misma manera que utilizando `printf`.

##### `int fputs(const char *str, FILE *stream);`
Copia la cadena de caracteres apuntada por `str` hasta encontrar el caracter de fin de texto `\0` al archivo apuntado por `stream`. El caracter de finalización `\0` no es copiado.

#### Organización de los datos en archivos de texto
Tenemos dos formas de orgnizar los archivos de texto: campos de longitud variable y campos de longitud fija. Al decir campos nos referimos a las diferentes unidades de datos que completan cada registro o fila del archivo.

**Campos de longitud variable:** Se define un caracter que separa cada uno de los campos del registro. Por ejemplo utilizando `|` como separador de campos:
```text
44444444|Persona Cuatro|A|1/4/2004|44000.44 
22222222|Persona Dos|B|1/2/2002|22000.25
33333333|Persona Tres|B|1/3/2003|33000.32
```

**Campos de longitud fija:** La longitud de cada campo se define de antemano y se respeta para todos los registros aunque sobre espacio sin utilizar. Por ejemplo si se define el campo `nombre` con 30 caracteres y un campo definido ocupa 14, se rellena con espacios al final.
```
44444444Persona Cuatro                        A01042004 44000.44
22222222Persona Dos 						  B01022002 22000.25
33333333Persona Tres                          B01032003 33000.32
55555555Persona Cinco                         A01052005 55000.50
01111111Persona Uno                           C01012001111000.10
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
`sizeof(array)`
retorna el tamaño en bytes del array referenciado.