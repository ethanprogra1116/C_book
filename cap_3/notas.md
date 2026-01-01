# Control Flow
- if
- else if (multi-decision)
- switch es extremadamente rapido.

## IF statements
con los || logicos se lee el primer elemento y si es falso se devuelve el segundo. Si es verdadero se devuelve verdadero.
Con el && logico se evalua el primero y si es falso se sale del loop, si es verdadero se devuelve el valor del segundo.

## Else-if
Bloque mas sencillo de decisiones multi-branch

## Switch statements
Cuando se cumple un caso se corren los demas a menos que explicitamente se ponga un break
Es buena practica poner un break en el default.

```C
// The for statement
for (expr1; expr2; expr3)
  statement;
// is equivalent to
expr1;
while (expr2) {
  statement;
  expr3;
}
// Except for the behaviour of continue


// Esta sintaxis es valida y es un bucle infinito
for(;;)

```

## Comma Operator
En digamos un for se puede separar por comas para por ejemplo tener varias inicializaaciones. Se evalua left to right.
- Las comas en las inicializaciones int a,b,c.
- Los argumentos de las funciones(a,b,c)
NO SE GARANTIZA la evaluacion de izquierda a derecha y no es un comma Operator.


## Loops
### Loops que se testean al inicio
while
for 

### Loops que se testean despues de ejecutar el body
do-while

Nota: Los signed int overflow es indefinido porque historicamente se usaban tres formas de representar los numeros negativos. Hoy en dia despues del C23 solo se permite el complemento a dos, pero el comportamiento sigue indefinido, el de unsigned int si esta definido
