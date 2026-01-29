// Calculadora de notacion polaca inversa.
// Programa hecho por mi from scratch ou yeah
#include <ctype.h>
#include <stdio.h>
#define MAXOP 500
double num_buff[MAXOP];
double *p = num_buff; // Puntero al proximo espacio disponible.
int evaluar_tipo(char *);
double read_number(char *);
void push(double);
double pop();

enum tipo {
    NUMERO,
    OPERADOR,
    SUMA,
    RESTA,
    MULT,
    DIVISION,
    INDEFINIDO
};

// Los operadores van a ser suma, resta, multiplicacion y división.

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Calculadora polaca inversa\nUso 2 2 +");
    }

    while (--argc > 0) {
        int type = evaluar_tipo(*++argv);
        double num, temp, numero1, numero2;
        num = temp = 0.0;
        switch (type) {
            case NUMERO:
                num = read_number(*argv);
                push(num);
                break;
            case SUMA:
                push(pop() + pop());
                break;
            case RESTA:
                temp = pop();
                push(pop() - temp);
                break;
            case MULT:
                push(pop() * pop());
                break;
            case DIVISION:
                temp = pop();
                push(pop() / temp);
                break;
        }
    }
    printf("El resultado es %.2f\n", num_buff[0]);
    return 0;
}

int evaluar_tipo(char *s) {
    char operador = s[0];
    if (isdigit(operador)) {
        return NUMERO;
    }

    switch (operador) {
        case '+':
            return SUMA;
        case '-':
            return RESTA;
        case '*':
            return MULT;
        case '/':
            return DIVISION;
    };

    return INDEFINIDO;
}

double read_number(char *s) {
    int c, div;
    double suma;
    suma = div = 0;
    static int cicle_count = 0;

    // printf("Entramos a read number, ciclo %d\n", ++cicle_count);
    while(isdigit(c = *s++) || c == '.' && c != '\0') {
        if (isdigit(c)) {
            suma = suma * 10 + (c - '0');
            // printf("Ciclo de enteros, la suma acumulada es %f\n", suma);
        } else if (c == '.') {
            // Numeros con punto decimal
            for (div = 0; (c = *(s++)) != '\0'; ++div) {
                suma = suma * 10 + (c - '0');
            }
            suma = suma / (div * 10);
            // printf("El numero final es %f\n", suma);
            break;
        }
    }
    // printf("El numero final es %f\n", suma);
    return suma;
}

double pop() {
    if (p < num_buff) {
        printf("Out of bounds\n");
        return 0.0;
    } else {
        return *--p;
    }
}

void push(double num) {
    if (p > num_buff + MAXOP) {
        printf("Stack full\n");
    } else {
        *p++ = num;
    }
}
