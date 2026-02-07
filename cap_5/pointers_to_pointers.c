#include <stdio.h>
int main(void) {
    int num = 10;
    int* p = &num;
    int** pp = &p;
    printf("El valor del puntero p es %d, el adress es %p\n", *p, p);
    return 0;
}
