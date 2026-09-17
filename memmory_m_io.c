#include <stdint.h>
#include <stdio.h>

int main(void) {

    /*
     * Lo cual quiere decir que 0x25 es un puntero volatil a un byte y
     * se desreferencia para asignarle un valor
     *
     * Este codigo no corre porque los primeros 4kb aprox del programa
     * estan reservados de igual forma
     * Pagina 0: 0x0-0xFFF
     */

    // Esto funciona en el arduino por ejemplo
    // *(volatile uint8_t *)0x24 = 32;
    uint8_t numero = 20;
    uint8_t* puntero = &numero;
    printf("el addres de numero es %p\n", (void *)puntero);
    // Por ejemplo: el addres de numero es 0x7ffe298c33d7
    // o sea el valor literal del puntero es 0x7ffe298c33d7
    // es lo que pasa con (volatile uint8_t *)0x24
    // y con el dereference esxribimos a esa direccion literal
}
