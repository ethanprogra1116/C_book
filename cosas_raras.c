// Aqui vamos a crear un array y vamos a acceder a indices que no estan inicializados

#include <stdio.h>
int main() {
    int array[1000];

    for (int i = 0; i < 1000; i++) {
        printf("El valor en este indice es %d\n", array[i]);
    }
    return 0;
}
