# The C programming language

## Capitulo 1

### C es el lenguaje de Unix.
- Es el lenguaje de POSIX
- El estandar es ANSI.
- Es poderoso con muchos operadore, pero es transparente con lo que pasa en la compu.
- Todos los programas entran a la funcion main primero.
- Los archivos .out son ejecutables
- El lenguaje es statement based, en vez de expresion based como Rust

### Estructuras de datos
- char
- float
- double
- int

**Modificadores**: short, long, unsigned
The **size** of the structures such as the ´int´ are **machine dependent**

Estructuras de datos = Arrays, structs, unions, pointers

functions que devuelven todas estas

### Datos que puede formatear printf
Seguido del %
si es %d es un int, un numero decimal en decimal por eso la d. Si le ponemos un numero como %6d es un decimal de 6 wide.
Si vemos un %f es un float, o un double y es %6.3f significa que se escriba con 6 caracteres wide y 3 valores despues del punto.
%o - octal
%d - decimal
%x - hecadecimal
%c - character
%s - string

### I/O
getchar() - lee un caracter
putchar() - escribe un caracter
printf() - Escribe un character-string formateado, tambien llamado string-literal


### Funciones
- main tiene que devolver 0 y debe de ser int main()
- Las demas funciones pueden devolver void, pero tienen que ir antes de main. No despues. Se declaran antes de usarse.
- Si declaramos las funciones al principio antes de main las podemos definir/ímplementar abajo de main.

### Declaraciones y definiciones
- Declaracion cuando se dice el nombre y la neturaleza de la variable
int i; es una declaracion
- Definicion cuando se le asigna memoria. 
i = 0; Aqui ya se le asigna storage


## Capitulo 2
### Int Constants
Constant: 1234
Long constant: 1234l
unsigned long constant: 123445ul
Pueden ser escritos con sufijos
0x es hexadecimal
0 es octal.

### Floating point Constants
Los floating point constants pueden tener
- 2.0 punto decimal
- 1e-2 exponente
- Son doubles por defecto, sufijo 'f' para indicar lo contrario.

### character constants
Son ints escritos con 'c'

### String constant
Tambien llamados string literals. Son una secuencia de caracteres por "" double quotes.
strlen() es una funcion para determinar lo largo de la cadena excluyendo el caracter nulo \0
Hay un header. string.h que sirve para este tipo de funciones.

### Enum constant
List of constant integer values
enum months { JAN = 1, FEB, MAR, APR, MAY, JUN,
JUL, AUG, SEP, OCT, NOV, DEC };

### Precedence of operators
Major
- Arithmetic operators
- Relational operators
- Equality operators, == 
- Logical operators. Primero && y despues ||

### Type convertions
En general se convierte del tipo mas chico al mas grande, para no perder informacion·

If either operand is long double, convert the other to long double.
· Otherwise, if either operand is double, convert the other to double.
· Otherwise, if either operand is float, convert the other to float.
· Otherwise, convert char and short to int.
· Then, if either operand is long, convert the other to long

Las comparaciones como 3>1 solo se convierten a 1 si es verdadero y a 0 si es falso.

Las operaciones de <math.h> usan operaciones de doble precision. Los floats no se convierten automaticamente a doubles.

### En las llamadas de funciones
Las llamdas son expresiones asi que si no tenemos un function prototype char y short se convierten a int y float a double

#### Type casting
Las variables pueden convertirse explicitamente de esta manera 
(type)expression

### Incremento y decremento
++i es preincremento
i++ es posincremento

Si los usamos en un array de esa forma
int i = 5;
s[++i]; //Accedemos al elemento 6
[i++]; //Accedemos al elemento 5 y despues incrementamos.


### Bitwise operators
& - AND. Usado para maskear, apagar bits.
| - OR.  Sirve para prender bits. 
^ - XOR. Es 1 donde sean diferentes y 0 donde sean iguales. 
<< - left shift. Recorre hacia la izquierda y llena con 0 

>> - right shift. Recorre todo a la derecha, dividir entre 2. Puede ser arithmetic shift o logical shift.

~ - One's complement. O sea convierte 0 a 1 y 1 a 0.

### Precedence and order of evaluation
Todos los operadores tienen associativity left-rigth a excepcion de 
- assignment operators and expressions
- Operador ternario ?:
- Operadores unarios
