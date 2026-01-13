// #define name replacement text

#include <stdio.h>
#define PI 3.1416
#define nombre "Ethan"
#define forever for(;;)
#define max(A, B) ((A) > (B) ? (A) : (B)) // No creo que sea muy bueno usarlo, pero existe
#define dprint(expr) printf(#expr " = %g\n", expr)
#define paste(front, back) front ## back
// Conditional Inclusion |  a way to include code selectively, depending on the value of conditions evaluated during compilation.
#if !defined(HDR)
#define HDR
#endif
// #elif
// #else

int main() {
    printf("Hola %s\n", nombre);
    printf("%g\n", PI + 3); //El %g es que sera %f si es chico el nummero y %e si es muy largo que es cientifico.
    dprint(3.0/7.0); // Esta expresion se evalua como una funcion, pero es un macro.
    return 0;
}
