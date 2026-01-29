
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#define MAXLINE 1000

/* find: print lines that match pattern from 1st arg */
int main(int argc, char *argv[]) {
    char *line = NULL;
    size_t size = 0;
    ssize_t len;
    int found = 0;

    if (argc != 2) {
        printf("Usage: find pattern\n");
    } else {
        while ((len = getline(&line, &size, stdin)) > 0) {
            if (strstr(line, argv[1]) != NULL) { //Retorna un puntero, pero solo nos importa si es nulo o no
                printf("%s", line);
                found++;
            }
        }
    }
    free(line);
    return found;
}
