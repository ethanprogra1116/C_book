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
