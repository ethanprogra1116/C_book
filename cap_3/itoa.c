
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void reverse(char original[], char reverseada[], int n);
void itoa(int n, char s[]);
void itoa_recursivo(int n, char s[]);
void reverse_iterativa(char original[], int n);
void reverse_recursiva(char str[], int len);

int main() {
    int x = 5500;
    char numero[100];
    char numero2[100];
    char string[] = "Holas";
    itoa(x, numero);
    itoa_recursivo(x, numero2);
    reverse_iterativa(string, 5);

    printf("El numero es %s\n", numero);
    printf("El numero con el metodo recursivo es %s\n", numero2);
    printf("El numero con reverse iterativa es %s\n", string);
    // La volteamos nuevamente
    reverse_recursiva(string, 5);
    printf("El string original es nuavamente %s\n", string);

    return EXIT_SUCCESS;
}

// Convierte un numero a una cadena de texto
void itoa(int n, char s[]) {
    int i, sign;
    char s_rev[1000];

    if ((sign = n) < 0) /* record sign */
        n = -n; /* make n positive */
    i = 0;

    do { /* generate digits in reverse order */
        s[i++] = n % 10 + '0'; /* get next digit */
    } while ((n /= 10) > 0); /* delete it */

    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s, s_rev, i);
    strcpy(s, s_rev);
}

void itoa_recursivo(int n, char s[]) {
    static int i = 0; //Static por que si no en cada variable se vuelve a inicializar
    if (n < 0) {
        s[i++] = '-';
        n = -n;
    }
    if (n / 10) {
        itoa_recursivo(n / 10, s);
    }
    s[i++] = n % 10 + '0';
    s[i] = '\n';
}


void reverse(char org[], char rev[], int n) {
    int i, len;
    i = 0;

    for (len = n - 1 ; len >= 0 ; --len) {
        rev[len] = org[i++];
    }

    org[i] = rev[i] = '\n';
    i++;
    org[i] = rev[i] =  '\0';
}


void reverse_iterativa(char str[], int n) {
    int a, b, temp;
    a = 0;
    b = n - 1;
    while ((b - a) >= 1) {
        temp = str[a];
        str[a] = str[b];
        str[b] = temp;
        a++;
        b--;
    }
}

void reverse_recursiva(char str[], int len) {
    int temp;
    static int a, b, len;
    // No necesitan static porque se pasan como argumento de la funcion.
    a = 0;
    b = len - 1;
    len -= 2;
    if (len <= 1) {
        return;
    }
    if ((b - a) >= 1) {
        a++;
        b--;
        reverse_recursiva(str, len);
    }
    temp = str[a]; //Inicio
    str[a] = str[b];
    str[b] = temp;
}
