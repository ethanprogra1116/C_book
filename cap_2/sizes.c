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

    printf("El largo de Int es de %ld\n", sizeof(var_int));
    printf("El largo de Short es de %ld\n", sizeof(var_short));
    printf("El largo de Long es de %ld\n", sizeof(var_long));
    printf("El largo de caracter es de %ld\n", sizeof(caracter));
    printf("El largo de float es de %ld\n", sizeof(var_float));
    printf("El largo de long double es de %ld\n", sizeof(long_double));
}
