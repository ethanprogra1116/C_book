#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#define M_PI 3.14159265358979323846

#include "calc.h" //Se escribe asi porque es local, no es de una libreria estandar
#define MAXOP 100

int main(void) {
    int type;
    double op2;
    bool resta = false;
    // Solo se guarda el valor actual por loop sea operador o numero.
    char s[MAXOP];

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
        case 's': // seno
            push(sin(pop() * M_PI / 180.0));
            break;
        case 'e': // exponencial
            push(sin(pop()));
            break;
        case '^': // power
            op2 = pop();
            push(pow(pop(), op2));
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
    return 0;
}
