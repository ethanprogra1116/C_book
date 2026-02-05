# Structures
Esto es lo mas parecido a un objeto y sirve para "POO" masomenos. No como en C++.
Struct es una coleccion de variables que pueden incluir structs que se asocian bajo un mismo nombre.
> The keyword struct introduces a structure declaration, which is a list of declarations enclosed
in braces.
- The variables named in a structure are called members.
- Pueden servir como una clase de namespace
- A structure can be initialized by following its definition with a list of initializers, each a constant expression.
- Se usa el dot notation para acceder a los miembros

## Punteros a structures
```C
struct {
    int len;
    char *s;
} *p;

// Equivalentes
(*p).len
p -> len
```
