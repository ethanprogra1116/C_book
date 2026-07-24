// CONCEPTO CLAVE: ARRAYS DE STRUCTS

// La forma normal sin pensarlo tanto seria asi, pero como son paralelas por eso
// hacemos el struct de arriba
// int keycount[NKEYS];
// char *keynames[NKEYS];

struct key {
    char *word;
    int count;
} keytab[] = {{"auto", 0},
              {"break", 0},
              {"case", 0},
              {"char", 0},
              {"const", 0},
              {"continue", 0},
              {"default", 0},
              /* ... */
              {"unsigned", 0},
              {"void", 0},
              {"volatile", 0},
              {"while", 0}};
// As a note... before the above structures were only separated by commas, not
// in sub-braces. it functions otherwise but this is more idiomatic and
// readable. the recomendation is always use them. because if we do not use all
// the camps it is an error waiting to ocurr. similar to the if of one line
// without braces

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#define NKEYS (sizeof keytab / sizeof(struct key))
#define MAXWORD 100

int getword(char *, int);
int binsearch(char *, struct key *, int);
/* count C keywords */
int main() {
    int n;
    char word[MAXWORD];
    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            if ((n = binsearch(word, keytab, NKEYS)) >= 0)
                keytab[n].count++;
    for (n = 0; n < NKEYS; n++)
        if (keytab[n].count > 0)
            printf("%4d %s\n", keytab[n].count, keytab[n].word);
    return 0;
}

/* binsearch: find word in tab[0]...tab[n-1] */
int binsearch(char *word, struct key tab[], int n) {
    int cond;
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        // strcmp returns <0 if word < tab[mid].word, 0 if equal, >0 if word >
        // tab[mid].word so we can use it to compare words alphabetically
        if ((cond = strcmp(word, tab[mid].word)) < 0)
            high = mid - 1;
        else if (cond > 0)
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}

/* getword: get next word or character from input */
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

    // Si no es alfanumerico solo devuelve el valor
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
