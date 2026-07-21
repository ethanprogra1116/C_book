#include <stdio.h>

int main(void) {

    // Se pueden declarar variables despues de la definicion del struct
    struct {
        int x;
        int y;
        int z;
    } x, y, z;
    // El patron entero de struct { ... } es analogo a poner int o
    // float, etc. Toda la declaracion es el tipo.

    x.x = 1; x.y = 2; x.z = 3;
    y.x = 4; y.y = 5; y.z = 6;
    z.x = 7; z.y = 8; z.z = 9;

    printf("%d %d %d\n", x.x, x.y, x.z);
    printf("%d %d %d\n", y.x, y.y, y.z);
    printf("%d %d %d\n", z.x, z.y, z.z);


    // Puede inicializarse de una sola vez
    struct {
        char *nombre;
        int edad;
    } persona1 = {"Sergio Ramos", 42};

    // Se puede declarar el esqueleto solamente
    struct point {
        int x;
        int y;
    };
    struct point p1 = {0, 0};


    return 0;
}
