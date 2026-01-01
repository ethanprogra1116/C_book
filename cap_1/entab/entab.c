/*
 Write a program entab that replaces strings of blanks by the minimum number
 of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab. When
 either a tab or a single blank would suffice to reach a tab stop, which should be given
 preference?
 */

#include <stdio.h>
#include <stdbool.h>
#define TAB_SPACES 8 // Estandar en Unix

int main() {
    int c;
    int recieved_spaces;//numero de espacios que voy a poner
    int num_blanks; // numero de blanks
    int num_tabs;
    bool in_word = false;

    num_blanks = num_tabs = recieved_spaces = 0;

    while((c = getchar()) != EOF) {
        if (c == ' ') {
            ++recieved_spaces;
            in_word = false;
        } else if (c == '\t') {
            putchar('\t');
        } else {
            in_word = true;
            // Print de los espacios
            num_tabs = recieved_spaces / TAB_SPACES;
            num_blanks = recieved_spaces % TAB_SPACES;
            for (int i = 0; i < num_tabs; ++i) {
                putchar('\t');
            }
            for (int i = 0; i < num_blanks; ++i) {
                putchar(' ');
            }
            // Print del char actual
            putchar(c);
            recieved_spaces = 0; // Para volver a contar
        }
    }
    return 0;
}
