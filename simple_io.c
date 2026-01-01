#include <stdio.h>

int main() {
    // Esta variable tiene que ser int para que pueda leer unsigned char o el EOF
    int c;

    // EOF es end of file - Ctrl+d en Linux y Mac
    while ((c = getchar()) != EOF ) {
        putchar(c);
    }


    printf("El string ha terminado\n El valor de eof es: %d \n", EOF);
    return 0;
}
