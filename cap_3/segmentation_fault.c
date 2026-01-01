// Este ejercicio era escape.c pero lo deje porque ilustra un concepto nuevo que es
// segmentation fault
#include <stdio.h>
void escape(char *s, char *t);
int main() {
    char t[] = "Hola claro que si\t\n";
    char s[100];
    escape(s, t);
    printf("Cadena t original %s\n, cadena s cambiada %s\n", t, s);
}

// String t to s changing special characters.
void escape(char s[], char t[]) {
    int i = 0;
    int j = 0;
    char actual;

    while ((actual = t[i]) != '\0') {
        switch (actual) {
        case '\t':
            t[j] = '\\';
            t[++j] = 't';
            break;
        case '\n':
            t[j] = '\\';
            t[++j] = '\n';
            break;
        default:
            t[j] = actual;
        }
        i++;
        j++;
    }
    t[j] = '\0';
}
