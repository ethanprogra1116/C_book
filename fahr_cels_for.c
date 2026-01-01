#include <stdio.h>

// En el The C programming language esto se define como
// symbolic constants
#define UPPER 300
#define LOWER 0
#define STEP 20

int main() {
    int fahr;

    // Aqui podemos solo inicializar la variable porque ya este declarada
    for (fahr = UPPER; fahr >= LOWER; fahr = fahr - STEP) {
        printf("%3d \t %3.1f\n", fahr, (5.0/9.0) * (fahr - 32));
    }
    return 0;
}
