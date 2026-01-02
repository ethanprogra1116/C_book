// Aqui vamos pusheando numeros al stack y cuando nos encontramos algun operador
// lo aplicamos y despues ya pusheamos ese valor al stack y seguimos, con los
// conmutativos no hay problema pero con las restas por ejemplo si.
// push es poner en el stack y pop es sacar del stack
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <math.h>
#include <stdbool.h>

#define MAXOP 100  /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */

int getop(char[]);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);

/* reverse Polish calculator */
int main(void) {
    int type;
    double op2;
    bool resta = false;
    // Solo se guarda el valor actual por loop sea operador o numero.
    char s[MAXOP]; // Lo usa getop para guardar el caracter actual, si es numero se transforma, si no solo se devuelve el operador.

    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            // Podria ser que es para numero negativo o operador
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero divisor\n");
            break;
        case '%':
            op2 = pop();
            if (op2 != 0.0)
                push((int)pop() % (int)op2);
            else
                printf("Error: Division por cero\n");
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
    return 0;
}

#define MAXVAL 100  /* maximum depth of val stack */
int sp = 0;         /* next free stack position */
// Aca se guardan puros valores numericos
double val[MAXVAL]; /* value stack */

/* push: push f onto value stack */
void push(double f) {
    if (sp < MAXVAL) {
        val[sp++] = f;
    } else {
        printf("error: stack full, can't push %g\n", f);
    }
}

/* pop: pop and return top value from stack */
double pop(void) {
    if (sp > 0) {
        return val[--sp];
    } else {
        printf("error: stack empty\n");
        return 0.0;
    }
}


/* getop: get next character or numeric operand */
// Si es un operador lo retornamos y si no lo es retornamos un 0 y el valor se queda guardado en el array que nos pasaron
int getop(char s[]) {
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t') // Eliminamos los espacios y los tabs. Se asigna un caracter valido
        ;
    s[1] = '\0'; // Despues de tener solo un caracter valido terminamos el string.
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
    s[i] = '\0'; //Cuando el while de arriba se cumpla se va a haber evaluado la expresion ++i aun siendo falso.

    /* Tambien para llegar a este punto estamos seguros que es un numero y leimos un caracter de mas */
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

#define BUFSIZE 100
char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0;      /* next free position in buf */

/* get a (possibly pushed-back) character */
int getch(void) { return (bufp > 0) ? buf[--bufp] : getchar(); } // Checa si hay caracteres en el bolsillo buf. Si no agarra uno nuevo
void ungetch(int c) { /* push character back on input */
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
