
#include <stdlib.h>
void reverse(char original[], char reverseada[], int n);
int main() {

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
    reverse(s, s_rev, n);
    s = s_rev;
}


void reverse(char original[], char reverseada[], int n) {
    int i, len;
    i = 0;

    for (len = n - 1 ; len >= 0 ; --len) {
        reverseada[len] = original[i];
        ++i;
    }

    original[i] = '\n';
    reverseada[i] = '\n';
    i++;
    original[i] = '\0';
    reverseada[i] = '\0';
}
