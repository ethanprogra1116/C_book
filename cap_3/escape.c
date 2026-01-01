
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
            s[j] = '\\';
            s[++j] = 't'; // En estos indices se incrementa antes de acceder al valor
            break;
        case '\n':
            s[j] = '\\';
            s[++j] = 'n'; // En estos indices se incrementa antes de acceder al valor
            break;
        default:
            s[j] = actual;
            break;
        }
        i++;
        j++;
    }
    s[j] = '\0';
}
