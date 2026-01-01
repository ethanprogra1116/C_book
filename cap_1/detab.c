#include <stdio.h>
#define NUMBER_OF_TABS 8

// Write a program detab that replaces tabs in the input with the proper number
// of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns.
int main() {
    int c;

    while((c = getchar()) != EOF) {
        if(c == '\t') {
            for (int i = 0; i < NUMBER_OF_TABS; i++) {
                putchar(' ');
            }
        } else {
            putchar(c);
        }
    }
    return 0;
}
