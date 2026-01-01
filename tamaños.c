#include <stdio.h>
#define LITERAL 1

int main() {
    int int_normal;
    char caracter;
    long int int_long;
    short int int_short;
    printf("El tamaño de variable int es de %ld bytes, el tamaño de int constante es de %ld bytes.\n", sizeof(LITERAL), sizeof(int_normal));
    printf("Tamaño de long int es %ld bytes, tamaño de short int es de %ld bytes.\n", sizeof(int_long), sizeof(int_short));
    printf("El tamaño de un caracter es de %ld byte\n", sizeof(caracter));
}
