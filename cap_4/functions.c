#include <stdio.h>

#define MAXLINE 1000 /* maximum input line length */

int get_line(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould"; /* pattern to search for */

/* find all lines matching pattern */
int main() {
  char line[MAXLINE];
  int found = 0;
  int indice;
  while (get_line(line, MAXLINE)) {
      indice = strindex(line, pattern);
      if (indice >= 0) {
      printf("%s", line);
      printf("El indice de la ultima instancia fue: %d\n", indice);
      found++;
    }
  }

  return found;
}

/* get_line: get line into s, return length */
int get_line(char s[], int lim) {
  int c, i;

  i = 0;
  while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
    s[i++] = c;

  if (c == '\n')
    s[i++] = c;

  s[i] = '\0';
  return i;
}

/* strindex: return index of t in s, -1 if none */
int strindex(char s[], char t[]) {
  int i, j, k;
  int max = -1;

  for (i = 0; s[i] != '\0'; i++) { // recorre todo el array s
    for (j = i, k = 0; t[k] != '\0' && s[j] == t[k];
         j++, k++) // j inicia en i, k en 0
      ;
    if (k > 0 &&
        t[k] == '\0') { // Aqui t[k] tiene que ser \0 si no quiere decir que no
                        // se llego al final de la coincidencia. Retorna -1

      if (i > max) {
        max = i;
      }
    }
  }

  return max;
}
