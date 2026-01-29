#include <stdio.h>
int main() {
    char lista[100];
    char *literal = "Hola";
    char buff[100];
    char *p = buff;

    printf("Tamaño de la lista: %ld\n", sizeof(lista));
    printf("Tamaño de un puntero a un literal %ld\n", sizeof(literal));
    printf("Tamaño del contenido de ese puntero %ld\n", sizeof(*literal));
    printf("Tamaño de un puntero a un buffer %ld\n", sizeof(p));
    printf("Tamaño del valor del buffer al que apunta el puntero %ld\n", sizeof(*p));
    return 0;
}
