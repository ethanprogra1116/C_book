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
