// Write a function reverse(s) that reverses the character string s. Use it to
// write a program that reverses its input a line at a time.
#include <stdio.h>
// Estas
void reverse(char original[], char reverseada[], int len);
void limpiar(char primera[], char segunda[], int largo_cadena);

int main() {
    char palabra[1000];
    char palabra_alreves[1000];
    int c, i;
    i = 0;
    printf("Danos una palabra y la reversearemos papu🦾\n");
    limpiar(palabra, palabra_alreves, 1000);
    while ((c = getchar()) != EOF) {
        if(c != '\n') {
            palabra[i++] = c;
        } else {
            reverse(palabra, palabra_alreves, i);
            printf("La original es %s", palabra);
            printf("La volteada es %s", palabra_alreves);
            limpiar(palabra, palabra_alreves, 1000);
            printf("El largo de la palabra es %d\n", i);
            i = 0; // Inicializamos para otra persona
        }
    }
}

// Voy a recibir un string sin \n y sin \0. Cuando detectemos un \n se va a actvar reverse
// Lo que tengo es un array de n largo, que podria
void reverse(char original[], char reverseada[], int n) {
    int i, len;
    i = 0;

    for (len = n - 1 ; len >= 0 ; --len) {
        reverseada[len] = original[i];
        ++i;
    }

    original[i] = '\n';
    reverseada[i] = '\n';
    i++;
    original[i] = '\0';
    reverseada[i] = '\0';
}

void limpiar(char primera[], char segunda[], int largo_cadena) {
    int i = 1;
    for (i = 0; i < largo_cadena; ++i) {
        primera[i] = 0;
        segunda[i] = 0;
    }
}
