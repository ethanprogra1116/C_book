#include <ctype.h>
#include <stdio.h>
#include "calc.h"
#define SIZE 1000
int getch(void);
void ungetch(int);

int main() {
    int n;
    double array[SIZE], getfloat(double *);
    for (n = 0; n < SIZE && getfloat(&array[n]) != EOF; n++)
        ;

    return 0;
}

double getfloat(double *pn) {
    int c, sign, i;
    while (isspace(c = getch())) /* skip white space */
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c); /* it is not a number */
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    if (c == '.') {
        c = getch();
        for (i = 0; isdigit(c); c = getch(), i++) {
            *pn = (10 * *pn) + (c - '0');
        }
        *pn = *pn / (10 * i);
    }
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}
