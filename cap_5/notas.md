# Pointers
Variables that carry the adress of another variable

& - Adress off. Accede al address de la variable.
* - Dereference operator. Accede al valor el que apunta el puntero.

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

*Principal diferencia de array names con Pointers* Los punteros son variables asi que puedo i++ y reasignarlos pa = a.

## Arrays
Equivalencias 
- El nombre de un array es igual que un & al primer elemento del array.
- En las declaraciones es posible declarar arr[] o *arr. Se prefiere la segunda porque define mejor lo que es. Un puntero.
- Si a una funcion le pasamos una arumento de tipo arr[2] o arr + 2, estamos pasando un subarray.


The header <stddef.h> defines a type ptrdiff_t that is
large enough to hold the signed difference of two pointer values.

Los *string literals* pueden ser definidos como punteros o como arrays, pero si cambias el valor de un elemento del puntero el comportamieto es UB.

## Pointer Arrays, pointers to pionters
Since pointers are variables themselves, they can be stored in arrays just as other variables can.
> La implementación de las listas en CPython esta fundada en este principio.
