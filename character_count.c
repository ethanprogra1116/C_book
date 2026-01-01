#include <stdio.h>
void ciclo_while();
void ciclo_for();

int main() {
    char decisiones;

    printf("Presiona 1 para el ciclo for, presiona 2 para el ciclo while: ");

    // Solo va a entrar este while si no se elige 1 o 2
    while ((decisiones = getchar()) != '1' && decisiones != '2') {
        printf("Solo se acepta un 1 o un 2 como argumento\n");
        while (getchar() != '\n');
    }

    getchar(); // consume el enter que quedo despues de elegir el 1 o el 2
    if (decisiones == '1') {
        ciclo_for();
    } else if (decisiones == '2') {
        ciclo_while();
    }

    return 0;
}

void ciclo_while() {
    long nc; // los long int son de 32 bits. Numeros posibles 2^32. 4,294,967,296
    nc = 0; //Importante porque si no nos dara undefined behavior.
    int c;
    printf("Entramos al ciclo while, escribe tus caracteres y presiona Ctrl+D para terminar\n");
    // Obtenemos el valor y solo lo sumamos si no es un enter.
    while ((c = getchar()) != EOF) {
        if (c != '\n') {
            ++nc;
        }
    }

    printf("%ld\n", nc);
}

void ciclo_for() {
    double nc;
    int c;
    printf("Entramos al ciclo for, escribe tus caracteres y presiona Ctrl+D para terminar\n");
    for (nc = 0; (c = getchar()) != EOF; ++nc) {
        if (c == '\n') {
            --nc; // Si es enter restamos el valor que ya habiamos sumado
        }
    }
    printf("%.0f\n", nc);
}
