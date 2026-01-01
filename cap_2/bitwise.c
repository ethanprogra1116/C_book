#include <stdio.h>
unsigned get_bits(unsigned x, int p, int n);
unsigned set_bits(unsigned x, int p, int n, int y);
unsigned inverted(unsigned x ,int p,int n);

int main() {
    printf("Hola gays\n");
    unsigned bits = get_bits(0b01010101,4,3);
    printf("Los bits son: 0b%b\n", bits);

    // Funcion set_bits
    unsigned res_set_bits = set_bits(0b01010101, 4,3, 0b10101010);
    printf("El resultado de res_set_bits es de %b\n", res_set_bits);

    // Funcion inverted
    unsigned res_inverted = inverted(0b01010101, 4,3);
    printf("El resultado de inverted es de %b\n", res_inverted);
    return 0;
}

// Agarra los bits desde la posicion p y loss n elementos
// la primera recorre hasta el final los elementos que queremos, luego
// ~(~0<<n) niega 0 o sea 11111 y lo recorre a la izquierda los lugares que queramos
// se queda 11111000 y luego lo negamos para que quede 00000111 y con el And nos quedamos solo con los ultimos bits.
unsigned get_bits(unsigned x, int p, int n) {
    return (x >> (p+1-n)) & ~(~0 << n);
}

// Write a function setbits(x,p,n,y) that returns x with the n bits that begin at
// position p set to the rightmost n bits of y, leaving the other bits unchanged.
unsigned set_bits(unsigned x, int p, int n, int y) {
    // Esta primera parte nos devuelve los ultimos digitos, completado con 0.
    // 0b00000101
    // 0b10100100
    // tengo que tener a y de forma 0b11111000
    // y eso ponerlo en un OR con mi expresion que ya tengo
    int x_modif = (x >> (p+1-n)) & ~(~0 << n);
    int y_modif = (~0 << n) & y;
    return x_modif | y_modif;
}

// Retorna los n numeros desde la posicion p invertidos(negados).
unsigned inverted(unsigned x ,int p,int n) {
    return  ~(~0<<n) & ~((x >> (p+1-n)) & ~(~0<<n));
}
