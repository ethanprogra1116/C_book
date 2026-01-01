#include <stdio.h>
int binary_search(int lista[], int x, int n);
int main() {
    int lista[] = {1,2,2,2,2,5,5,5,7,8,8,8,9};
    // Voy a buscar el numero 7
    binary_search(lista, 7, 13); // El indice maximo es n-1
    return 0;
}

// Buscamos el Int x en la lista lista[] y devolvemos el indice. n es el numero de elementos
// MI VERSION
int binary_search(int lista[], int x, int n) {
    int low, medium, high, temp;
    // Posiciones de indices
    low = 0;
    high = n - 1;
    medium = high / 2; // Importante que sea int para no tener float subscripts
    while (lista[medium] != x) {
        if(lista[medium] > x) {
            temp = medium;
            high = temp;
            medium = (high + low) / 2;
        } else {
            temp = medium;
            low = temp;
            medium = (high + low) / 2;
        }
    }
    printf("Se encontro en valor %d en la posicion media la cual esta en %d\n", lista[medium], medium);
    return medium; // Retornamos el indice
}


// VERSION DEL LIBRO
int binsearch(int x, int v[], int n) {
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low+high)/2;
        if (x < v[mid])
            high = mid + 1;
        else if (x > v[mid])
            low = mid + 1;
        else /* found match */
            return mid;
    }
    return -1; /* no match */
}
