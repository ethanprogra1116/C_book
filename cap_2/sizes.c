// Imprimir los valores de los char, int, long, double signed y unsigned

#include <stdio.h>
#include <limits.h>
#include <float.h>
int main() {
    int var_int;
    short var_short;
    long var_long;
    char caracter;
    float var_float;
    long double long_double;
    var_int = var_short = var_long = caracter = 0;
    var_float = long_double = 0.0;
    typedef struct {
        int edad;
    } Persona;

    Persona *pp;
    Persona ethan;
    pp = &ethan;

    printf("el largo de int es de %ld\n", sizeof(var_int)); // result: 4
    printf("el largo de short es de %ld\n", sizeof(var_short)); // result: 2
    printf("el largo de long es de %ld\n", sizeof(var_long)); // result: 8
    printf("el largo de caracter es de %ld\n", sizeof(caracter)); // result: 1
    printf("el largo de float es de %ld\n", sizeof(var_float)); // result: 4
    printf("el largo de long double es de %ld\n", sizeof(long_double)); // result: 8
    printf("el tamaño de es %lu\n", sizeof(Persona)); // result: 4
    printf("El tamaño de un puntero a un struct es %lu\n", sizeof(pp)); // result: 8
    printf("un puntero a un struct es %s que un int\n", (sizeof(NULL) > sizeof(int) ? "mayor" : "menor")); // result: menor
}
