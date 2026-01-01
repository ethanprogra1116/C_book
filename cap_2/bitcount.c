#include <stdio.h>
int bitcount(unsigned x);
int main(){
    int numero = 0b110101011;
    int numero_de_bits = bitcount(numero);
    printf("El numero de bits es %d\n", numero_de_bits);
    return 0;
}

int bitcount(unsigned x) {
    int b;
    for (b = 0; x != 0; x &= (x-1) ) // x >>= 1
        if (x & 01) // Notar que no es un AND logico sino bitwise, 01 es octal 1.
                    // En los sistemas UNIX normalmente se usaba octal, hoy en dia es hexadecimal
                    // Se usa como bitmask temporal, se evalua cada iteracion.
        b++;
    return b;
}
