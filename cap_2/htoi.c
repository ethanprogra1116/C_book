// Declaración de headers y declaración de funciones.
#include <ctype.h>
#include <stdio.h>

int htoi(char s[]);

enum hexa {
    A = 10,B,C,D,E,F
};

int main() {
    char *texto = "a0184eefc";
    int decimal = htoi(texto); // Funciona porque los arrays se pasan por referencia.
    printf("Conversion de %s a decimal es de %d\n", texto, decimal);

}

int htoi(char s[]) {
    int numero_en_decimal = 0;
    // Determinar el largo del array
    int i = 0; // Iterador
    int array_len = 0; //Conteo del largo del array
    int c; // Current character

    while ((c = s[i]) != '\0') {
        ++array_len;
        ++i;
    }

    // En este array se van a poner todos los numeros que
    int array_numeros[array_len];

    // Si mi array tiene 5 elementos mi array_length solo tendra 4 elementos, pero esos son los que necesito para iterar, el
    // \0 no lo necesito.
    if (s[0] == '0' && s[1] == 'x') {
        // Quiere decir que es de 3 al final
        for (int i = 2; i < array_len; ++i) {
            if (isdigit(c)) {
                array_numeros[i-2] = c - '0';
            } else {
                switch (c) {
                    case 'a':
                    case 'A':
                        array_numeros[i-2] = A;
                        break;

                    case 'b':
                    case 'B':

                        array_numeros[i-2] = B;
                        break;

                    case 'c':
                    case 'C':

                        array_numeros[i-2] = C;
                        break;

                    case 'd':
                    case 'D':

                        array_numeros[i-2] = D;
                        break;

                    case 'e':
                    case 'E':

                        array_numeros[i-2] = E;
                        break;

                    case 'f':
                    case 'F':

                        array_numeros[i-2] = F;
                        break;
                }
            }
            // array_numeros[i-2] = s[i];
        }

    } else {
        // Empezamos desde el indice 0 al final
        for (int i = 0; i < array_len; ++i) {
            if (isdigit(c)) {
                array_numeros[i] = c - '0';
            } else {
                switch (c) {
                    case 'a':
                    case 'A':
                        array_numeros[i] = A;
                        break;

                    case 'b':
                    case 'B':

                        array_numeros[i] = B;
                        break;

                    case 'c':
                    case 'C':

                        array_numeros[i] = C;
                        break;

                    case 'd':
                    case 'D':

                        array_numeros[i] = D;
                        break;

                    case 'e':
                    case 'E':

                        array_numeros[i] = E;
                        break;

                    case 'f':
                    case 'F':

                        array_numeros[i] = F;
                        break;
                }
            }
        }

    }

    // Proceso de conversion
    for (int i = 0; i < array_len; ++i) {
        numero_en_decimal = numero_en_decimal * 16 + array_numeros[i];
    }
    return numero_en_decimal;
}
