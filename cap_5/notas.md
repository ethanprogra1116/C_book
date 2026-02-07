# Pointers

Variables that carry the adress of another variable

& - Adress off. Accede al address de la variable.

-   - Dereference operator. Accede al valor el que apunta el puntero.

Utiles porque en las funciones los argumentos se pasan por valor y no por referencia, asi que se afectarian copias de los valores.

A las funciones les pasamos la referencia de las variables &

## Pointer arithmetic

Si yo tengo un snippet

```C
int buff[100];

// puntero
int *pa = &buff[0];

printf("Valor de buff[1], con punteros" *(pa + 1) )
```

El significado de sumar 1 a un puntero quiere decir el siguiente elemento no importa el tamaño de el array ni el tipo

_Principal diferencia de array names con Pointers_ Los punteros son variables asi que puedo i++ y reasignarlos pa = a.

## Arrays

Equivalencias

- El nombre de un array es igual que un & al primer elemento del array.
- En las declaraciones es posible declarar arr[] o \*arr. Se prefiere la segunda porque define mejor lo que es. Un puntero.
- Si a una funcion le pasamos una arumento de tipo arr[2] o arr + 2, estamos pasando un subarray.

The header <stddef.h> defines a type ptrdiff_t that is
large enough to hold the signed difference of two pointer values.

Los _string literals_ pueden ser definidos como punteros o como arrays, pero si cambias el valor de un elemento del puntero el comportamieto es UB.

## Pointer Arrays, pointers to pionters

Since pointers are variables themselves, they can be stored in arrays just as other variables can.

> La implementación de las listas en CPython esta fundada en este principio.

## Argumentos de funciones
Cuando se pasa un array multidimensional no importan las filas, solo se tienen que especificar las columnas
```C
char multidimensional[2][2] = {
    {2, 3},
    {4, 5}
}; 

int funcion(array[][]) {
    printf("Hola gays");
}

int main(void) {
    funcion(multidimensional[][2])
}

```

## Declaracion de punteros a char arrays
Retorna un puntero a el string literal en la posicion name[]
```C
/* month_name: return name of n-th month */
char *month_name(int n)
{
    static char *name[] = {
        "Illegal month",
        "January", "February", "March",
        "April", "May", "June",
        "July", "August", "September",
        "October", "November", "December"
    };
    return (n < 1 || n > 12) ? name[0] : name[n];
}
```

## Command Line Arguments
En linux, y en otros entornos tambien los argumentos que se le pasan a un ejecutable entran a un array con estos.
Argc es el count
argv es un puntero al array que tiene los valores.
```C
int main(int argc, char *argv[]) {
    
    return 0;
}
```
> *Nota*:  argv[argc] tiene que ser igual a un NULL pointer.

## Punteros a funciones
```C
qsort((void **)lineptr, 0, nlines - 1,
              (int (*)(void *, void *))(numeric ? numcmp : strcmp));
```
En este ejemplo qsort, numcmp y strcmp son addresses de functions. Los & estan implicitos, al igual que con el nombre de un array que es &array[0]. Esto pasa porque son simbolos que conoce el compilador ya de antemano.

**Generic pointer**: void *

Dato: La adicion de punteros es ilegal, la substraccion es legal.
