// Implementacion de Strings usando punteros

#include <stdio.h>
#include <stdlib.h>

int strcats(char *s, char *t);

int main() {
    char s[1000] = "Primer String ";
    char t[1000] = "Segundo string ostias";

    strcats(s, t);
    printf("El string es \"%s\"\n", s);
    return 0;
}

int strcats(char *s, char *t) {

    while (*s != '\0') {
        s++;
    }

    // Bucle que a partir de la posicion s empieza a copiar t hasta que el valor
    do {
        *s++ = *t++;
    } while (*t != '\0');

    return EXIT_SUCCESS;
}
