
#include <stdio.h>
#include <string.h>
#define MAXLINES 5000    /* max #lines to be sorted */
#define MAXLEN 1000 /* max length of any input line */
char *lineptr[MAXLINES]; /* pointers to text lines */
int readlines(char *lineptr[], int nlines);
static int get_line(char *, int);
void writelines(char *lineptr[], int nlines);
void qsort(void *lineptr[], int left, int right, int (*comp)(void *, void *));
int numcmp(char *, char *);

/* sort input lines */
int main(int argc, char *argv[]) {
    int nlines;      /* number of input lines read */
    int numeric = 0; /* 1 if numeric sort */

    if (argc > 1 && strcmp(argv[1], "-n") == 0) {
        numeric = 1;
    }

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        qsort((void **)lineptr, 0, nlines - 1,
              (int (*)(void *, void *))(numeric ? numcmp : strcmp));
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("input too big to sort\n");
        return 1;
    }
}

/* readlines: read input lines returns nlines*/
int readlines(char *lineptr[], int maxlines) {
    // Variables antiguas
    int len, nlines;
    char line[MAXLEN]; // Current line. Solo una

// Variables de allocator
#define ALLOCSIZE 10000
    static char allocbuf[ALLOCSIZE]; /* storage for alloc */
    static char *allocp = allocbuf;  /* next free position */

    nlines = 0;
    while ((len = get_line(line, MAXLEN)) > 0)
        if (nlines >= maxlines ||
            (allocbuf + ALLOCSIZE - allocp) <
                len) { // No cabe o ya llegamos al maximo de lineas
            return -1;
        } else {
            line[len - 1] = '\0'; /* delete newline */
            strcpy(allocp, line);
            lineptr[nlines++] = allocp;
            allocp += len;
        }
    return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines) {
    int i;
    for (i = 0; i < nlines; i++) {
        printf("%s\n", lineptr[i]);
    }
}

/* getline: read a line into s, return length */
static int get_line(char s[], int lim) {
    int c, i;
    // Copiamos todos los valores, excepto \n y paramos cuando sea EOF
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }

    // Para este punto ya salimos del for entonces agregamos el \n final
    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    // Antes de aqui incrementamos otra vez y ponemos el \0 end of string.
    s[i] = '\0';
    return i;
}

/* qsort: sort v[left]...v[right] into increasing order */
void qsorts(char *v[], int left, int right) {
    int i, last;
    void swap(char *v[], int i, int j);
    if (left >= right) /* do nothing if array contains */
        return;        /* fewer than two elements */
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsorts(v, left, last - 1);
    qsorts(v, last + 1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(char *v[], int i, int j) {
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
