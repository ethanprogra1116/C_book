// Convertimos un numero hexadecimal con 0x opcional de string a un numero real
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int atois(char *s);

int main() {
    // Funcion original
    int conversion = atoi("73373027");
    int conversion_2 = atois("73373027");
    printf("La conversión fue %d\n", conversion);
    printf("La conversión con mi método fue de %d\n", conversion_2);
}

// Convertimos un numero de un string a un numero decimal.
int atois(char s[]) {
    int  i, j, mult, total;
    // double multiplier, total;
    total = 0;
    // Si mi array es de 10 elementos 9 son numeros, el indice mayor sera 8
    for (i = 0; s[i] != '\0'; i++)
        ;

    for (mult = i, j = 0; mult >= 0 && s[j] != '\0' ; mult--, j++) {
        printf("El numero actual es %c, y el equivalente es %f\n", s[j], ((s[j] - '0') * pow(10, mult - 1)));
        total += (s[j] - '0') * pow(10, mult - 1);
        printf("El total hasta el momento es de %d\n", total);
    }

    printf("El total es de %d\n", total);
    return total;
}
