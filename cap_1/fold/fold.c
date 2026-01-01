/*
 Write a program to ``fold'' long input lines into two or more shorter lines after
 the last non-blank character that occurs before the n-th column of input. Make sure your
 ll program does something intelligent with very long lines, and if there are no blanks or tabs
 before the specified column.
 */
#include <stdio.h>
#define LINE_LIMIT 50

int main() {
    int c;
    int num_char;
    num_char = 0;
    while ((c = getchar()) != EOF) {
        // Gestion del numero de lineas.
        ++num_char;
        if (c == '\t') {
            num_char += 8;
        } else if (c == '\n') {
            // Esto era necesario porque si no solo funcionaba con la primer linea de input. No con las demas
            putchar(c);
            num_char = 0;
        }

        // Gestion de escribir los caracteres
        if (num_char > LINE_LIMIT ) {
            if (c == '\t' || c == ' ') {
                putchar('\n');
                num_char = 0;
            } else {
                // Esto es si es una palabra normal. Hay que ponerle un - para decir que la palabra continua
                putchar('-');
                putchar('\n');
                putchar(c);
                num_char = 0;
            }
        } else if (c == '\t') {
            for (int i = 0; i < 8; ++i) {
                putchar(' ');
            }
        } else {
            putchar(c);
        }
    }

    return 0;
}
