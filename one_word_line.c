#include <stdio.h>
#include <stdbool.h>
#include <threads.h>

int main() {
    // Leemos input e imprimimos una palabra por linea.
    // Cada que haya whitespace se tiene que imprimir otra linea
    int c;
    bool limit_reached;
    limit_reached = false;

    printf("Escribe frases y las imprimire una por una\n");
    while ((c = getchar()) != EOF) {
        if (c == '\n' || c == ' ' || c == '\t') {
            if (!limit_reached) {
                putchar('\n');
                limit_reached = true;
            }
        } else {
            putchar(c);
            limit_reached = false;
        }
    }
    printf("Loop finalizado con exito\n");
    return 0;
}
