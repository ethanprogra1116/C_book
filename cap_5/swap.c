// Codigo que hace swap de 2 variables pasadas por referencia

#include <stdio.h>
#include <stdlib.h>

void swap(int *px, int *py);


int main(void){
    int x,y;
    x = 6;
    y = 1;
    printf("Antes del print x valia %d, y \"y\" valia %d\n", x, y);
    swap(&x, &y);
    printf("Despues del print x vale %d, y \"y\" vale %d\n", x, y);
    return EXIT_SUCCESS;
}

// Pointers para poder afectar los datos reales.
void swap(int *px, int *py) {
    int temp;
    temp = *px;
    *px = *py;
    *py = temp;
}
