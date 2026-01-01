#include <stdio.h>
#define MAXLINE 1000

int main() {

    getline(char **restrict lineptr, size_t *restrict n, FILE *restrict stream)
    return 0;
}



int getlines(void) {
    int c, i;
    extern char line[];
    for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    line[i] = c;
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}
