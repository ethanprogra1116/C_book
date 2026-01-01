#include <stdio.h>

int main() {
    // Declaracion de varables
    int upper, lower, step;
    float faren, cels;

    // Definicion de variables
    upper = 300;
    lower = 0;
    step = 20;

    // Inicializamos los valores
    cels = lower;

    // Aqui ponemos el header
    printf("Farenheit \t Celcius\n");
    // Convertimos de celcius a farenheit
    while (faren <= upper) {
        faren = cels / (5.0 / 9.0) + 32;
        printf("%3.2f \t\t %3.2f \n", faren, cels);
        cels += step;
    }

    return 0;
}
