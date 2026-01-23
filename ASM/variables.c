#include <stdio.h>

int main() {

    int a,b,c;
    a = 10;
    b = 100;
    c = 1000;

    char string[] = "Hola, este string es modificable";
    char *string2 = "Este string no es modificable";

    printf("String modificable %s\nString no modificable%s\n", string, string2);
}
