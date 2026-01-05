#include <stdio.h>
#include <ctype.h>
#include "calc.h"

int getop(char s[]) {
    int i, c;
    while ((s[0] = c = getch()) == ' ' ||
           c == '\t') // Eliminamos los espacios y los tabs. Se asigna un
                      // caracter valido
        ;
    s[1] =
        '\0'; // Despues de tener solo un caracter valido terminamos el string.
    if (!isdigit(c) && c != '.' && c != '-')
        return c; /* not a number */
    i = 0;
    if (c == '-') {
        c = getchar();
        if (!isdigit(c) && c != '.') {
            ungetch(c);
            return '-';
        }
        s[++i] = c;
    }
    if (isdigit(c)) /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.') /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0'; // Cuando el while de arriba se cumpla se va a haber evaluado
                 // la expresion ++i aun siendo falso.

    /* Tambien para llegar a este punto estamos seguros que es un numero y
     * leimos un caracter de mas */
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}
