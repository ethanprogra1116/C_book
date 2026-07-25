#include <ctype.h>
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


int getword(char *word, int lim) {
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
