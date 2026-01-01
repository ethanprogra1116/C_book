#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>

double atofs(char *s);

int main() {
    char *decimal = "12349823";
    char *flotante = "123212.1213131";
    int decimal_convertido = atoi(decimal);
    double flotante_convertido = atof(flotante);
    double llamada_atofs = atofs("123.456");
    double atofs_exp = atofs("123.456e-1");

    printf("El numero con punto decimal es %d y el de punto flotante es %.10f\n", decimal_convertido, flotante_convertido);
    printf("El numero con la funcion mio %f\n", llamada_atofs);
    printf("El numero con exponencial e-1 es %f\n", atofs_exp);
    return 0;
}


// Implementacion del libro de atof
double atofs(char s[]) {
    int i, sign;
    double val, power, exp;

    // Eliminamos el whitespace
    for(i = 0; isspace(s[i]) ; i++)
        ;

    // Signo, parecido a la asignación con if de Rust, solo que mas viejo
    sign = (s[i] == '-') ? -1 : 1;

    // Empezamos a guardar el numero
    for (val = 0.0 ; isdigit(s[i]); i++) {
        val = val * 10 + (s[i] - '0');
    }

    if (s[i] == '.') {
        i++;
    }

    for (power = 1.0; isdigit(s[i]); i++) {
        val = val * 10 + (s[i] - '0');
        power *= 10; // Vamos incrementando un valor que luego restaremos
    }


    // Manejar parte exponencial
    val = sign * val / power;

    if (s[i] == 'e' || s[i] == 'E' ) {
        printf("Tenemos un exponencial\n");
        sign = (s[i + 1] == '-') ? -1 : 1;

        // Si tienen simbolo de signo lo quitamos
        if (s[i + 1] == '-' || s[i + 1] == '+') {
            i++;
        }
        // while (isdigit(s[i])) {
        //     val = val * 10 + (s[i++] - '0');
        // }

        // Guardo el numero
        for (exp = 1.0; isdigit(s[i]); i++) {
            exp = exp * 10 + (s[i] - '0');
        }

        // Convierto el numero a la magnitud
        exp = pow(10, exp);

        // Segun el signo es si se multiplica o se divide
        if (sign > 0) {
            return val * exp;
        } else {
            return val / exp;
        }

        return val *= exp;
    }
    // Si no se entra al if
    return val ;
    // return sign * val / power;
}

// X ^ 2
