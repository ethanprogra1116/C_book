#include <stdio.h>
#include <stdbool.h> // En C++ si hay booleanos y aparte Strings.
#include <stdint.h>

// Blanks, tabs and newlines
void counting_special_chars() {
    int blanks, tabs, newlines, c;
    blanks = tabs = newlines = 0;

    while((c = getchar()) != EOF) {
        if (c == ' ') {
            blanks++;
        } else if (c == '\t') {
            tabs++;
        } else if (c == '\n') {
            newlines++;
        }
    }

    printf("Los blanks son %d, los tabs son %d y los newlines son %d. \n", blanks, tabs, newlines);
}

// Trim extra spaces. Copia el string, pero quita los espacios extra
void trim_spaces() {
    bool limit_reached = false;
    int c;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            if (limit_reached == false) {
                putchar(c);
                limit_reached = true;
            }
        } else {
            limit_reached = false;
            putchar(c);
        }
    }
}


// Mostrar los \t, \b y \\. Como string.
void mostrar_invisibles() {
    int c;
    printf("kccnuadcnoi");
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            putchar('\\');
            putchar('t');
        } else if (c == '\b') {
            putchar('\\');
            putchar('b');
        } else if (c == '\\') {
            putchar('\\');
            putchar('\\');
        } else {
            putchar(c);
        }
    }
}



int main() {
    int decisiones;

    printf("Dame un numero.\n");
    printf("Con el numero 1 se cuentan los caracteres especiales blanks, tabs y newlines\n");
    printf("Con el numero 2 se borran los blanks extras\n");
    printf("Con el numero 3, se muestran los \\t, los \\b y los \\\\\n");

    while ((decisiones = getchar()) != '1' && decisiones != '2' && decisiones != '3') {
        printf("Solo se acepta un 1, 2 o 3 como argumento\n");
        while (getchar() != '\n'); //Limpia el buffer

    }

    //Limpia el buffer
    while (getchar() != '\n');
    if (decisiones == '1') {
         counting_special_chars();
     } else if (decisiones == '2') {
         trim_spaces();
     } else {
         mostrar_invisibles();
     }

    return 0;
}
