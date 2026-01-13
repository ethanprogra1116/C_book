# Functions
Este capitulo habla de funciones y modularidad.

## Compilacion
*gcc* o cc, es lo mismo
Si tenemos un codigo que usa codigo de distintos sources lo que hace es si por ejemplo hacemos
gcc main.c funcion1.c funcion2.c 

El *output* es:
main.o funcion1.o y funcion2.o

Después esto se convierte en un *archivo ejecutable*
a.out.

Si algo sale mal podemos recompilar solo el source code de ese archivo.

*Ejercicio para functions.c*
-------------------------------------------------------------------------------------
Write the function strindex(s,t) which returns the position of the rightmost
occurrence of t in s, or -1 if there is none
-------------------------------------------------------------------------------------

Primero hacemos un bucle que recorre todo el string s.
En cada iteracion si s[j] es igual a t[k] incrementamos los indices.
Primero j es 0 y k es 0, luego j es 1 y k es 0, luego j es 2.
Entonces mediante j y k podemos tener desde donde empezamos que es i, y solo modificamos el j 
Si j es mayor a 0 quiere decir que si estuvo la palabra retornamos en donde fue el indice i donde se encontro.


## Linkage

### External
Las funciones y las variables globales pueden ser external linkeables por defecto
```C
// archivo1.c
int contador = 0;  // external linkage
void incrementar() {  // external linkage
    contador++;
}

// archivo2.c
extern int contador;  // declara que existe en otro archivo
extern void incrementar();

int main() {
    incrementar();  // Puede usar la función de archivo1.c
    printf("%d", contador);  // Puede usar la variable de archivo1.c
}
```

### Internal
Se logra usando la palabra clave static
```C
// archivo1.c
static int privado = 10;  // Solo visible en archivo1.c
static void funcion_interna() {  // Solo visible en archivo1.c
    privado++;
}

// archivo2.c
extern int privado;  // ¡ERROR! No puede acceder
```
Internal static variables are
local to a particular function just as automatic variables are, but unlike automatics, they remain
in existence rather than coming and going each time the function is activated.

*Nota*: Esto es importante porque sirve en las funciones que cierran y mantienen estado. Que devuelven una funcion.
Difiere en el sentido en que en js puedes tener varias instancias de ese closure y aqui no.


Pendientes: Modify getop so that it doesn't need to use ungetch. *Hint:* use an internal static variable


### Registers
Ademas de static se puede usar la palabra clave register para decirle a la computadora que guarde la variable en un registro para ejecutarla mas rapidamente. El compilador puede ignorarla o no.
Se pueden declarar en funciones o en la firma de los parametros de una funcion cuando se defina.

## Inicializaciones automaticas
*externas* y *static* son inicializadas a 0 segun el estandar.
*Automatic* tienen garbage.

En los *Arrays* las variables son inicializadas a 0 si hay menos inicializadores que tamaño de array.

## Los macros 
El sistema de macros consiste de 
#include que incluye las declaraciones y defines de otros archivos
#define define macros, hay macros con argumentos 
#define sum(x) x + x 

### Operador ##
En la macro expansion se concatenan argumentos con ##
#define paste(front, back) front ## back

### Operadores condicionales
If this style is used consistently, then each header can itself include any other
headers on which it depends, without the user of the header having to deal with the
interdependence.
```C
// Conditional Inclusion |  a way to include code selectively, depending on the value of conditions evaluated during compilation.
#if !defined(HDR)
#define HDR
#endif
// #elif
// #else
```
En vez de !defined podriamos usar #ifndef o #ifdef
