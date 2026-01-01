// Ver que pasa cuando accedemos a una variable declarada, pero no inicializada.

#include <stdio.h>
int main() {
    int primera, segunda;
    primera = 0;
    printf("%d\n",primera);
    // Esta segunda da pura mierda, porque no esta inicializada. Dara un valor random diferente cada vez.
    printf("%d\n", segunda);
}
