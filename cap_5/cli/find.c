#include <stddef.h>
#include <stdio.h>
#include <string.h>
#define MAXLINE 1000


/* find: print lines that match pattern from 1st arg */
int main(int argc, char *argv[]) {
    char *line = NULL;
    size_t size = 0;
    ssize_t len;
    long lineno = 0;
    int c, except = 0, number = 0, found = 0, reverse = 0;

    // Variables de flag -r
    char **lines[MAXLINE];
    long lineno_rev[MAXLINE];
    int i = 0;

    while (--argc > 0 && (*++argv)[0] == '-')
        while ((c = *++argv[0]))
            switch (c) {
            case 'x':
                except = 1;
                break;
            case 'n':
                number = 1;
                break;
            case 'r':
                reverse = 1;
                break;
            default:
                printf("find: illegal option %c\n", c);
                argc = 0;
                found = -1;
                break;
            }
    if (argc != 1) {
        printf("Usage: find -x -n pattern\n");
    } else {
        while (getline(&line, &size, stdin) > 0) {
            lineno++;
            if ((strstr(line, *argv) != NULL) != except) {
                if (reverse) {
                    lines[i] = &line;
                    lineno_rev[i++] = lineno;
                } else {
                    if (number)
                        printf("%ld:", lineno);
                    printf("%s", line);
                }
                found++;
            }
        }

        // Si llegamos a este punto es porque se tiene que imprimir en reversa;
        if (reverse) {
            for(int i = found-1; i >= 0; --i ) {
                if (number) {
                    printf("%ld:", lineno_rev[i]);
                }
                printf("%s", *(lines[i]));
            }
        }

    }
    return found;
}
