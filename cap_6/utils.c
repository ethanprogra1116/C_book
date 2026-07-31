#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;

/* get a (possibly pushed-back) character */
int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
} // Checa si hay caracteres en el bolsillo buf. Si no agarra uno nuevo

void ungetch(int c) { /* push character back on input */
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

int getword(char *word, int lim, bool inc_comments, bool inc_strings) {
    int c, getch(void);
    void ungetch(int);
    char *w = word;
    // Eliminamos todos los espacios en blanco. Un tipo trim()
    while (isspace(c = getch()))
        ;

    // Configura el inicio del string
    if (c != EOF)
        *w++ = c;

    // Si no es una letra solo devuelve el valor
    if (!isalpha(c)) {
        if (c == '/' && !inc_comments) {
            // TODOS LOS CASOS DE COMENTARIOS
            c = getch();
            if (c == EOF) {
                w--;
                *w++ = c;
                *w = '\0';
                return c;
            } else if (c == '*') {
                /* COMENTARIO LARGO */
                while ((c = getch()) != EOF) {
                    if (c == '*') {
                        if ((c = getch()) == '/') {
                            break;
                        } else if (c != EOF) {
                            ungetch(c);
                        }                    }
                }
            } else if (c == '/') {
                /* COMENTARIO CORTO */
                while ((c = getch()) != EOF && c != '\n')
                    ;
            } else {
                ungetch(c);
            }
        } else if (c == '\"' && !inc_strings) {
            // Mientras c sea diferente a " me como los caracteres
            // a menos que c sea me como el \ porque no es "
            // ejemplo: "hola como estan \" "
            while ((c = getch()) != '\"' && c != EOF) {
                if (c == '\\')
                    getch(); // Nos comemos un caracter extra
            }
        } else if (c == '\'' && !inc_strings) {
            while ((c = getch()) != '\'' && c != EOF) {
                if (c == '\\')
                    getch();
            }
        }
        *w = '\0';
        return c;
    }

    // Guarda el resto del string
    for (; --lim > 0; w++)
        if (!isalnum(*w = getch())) {
            ungetch(*w);
            break;
        }
    *w = '\0';
    return word[0];
}
