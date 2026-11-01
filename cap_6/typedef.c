#include <stdlib.h>
// Typedef ocupa dos argumentos, el tipo y el alias. el tipo puede
// ser un struct todo raro
typedef int Length;
Length len, maxlen;
Length *lengths[1]; //es un array de punteros a ints
typedef char *String; // an array og chars. hence, the definition of a string.
#define MAXLINES 100

typedef struct {
    int x;
    int y;
} Coords;

typedef struct tnode *TPointer ;

// Typedefs for tree nodes
typedef struct tnode {
    char* word;
    int count; /* veces que ha aparecido la palabra */
    struct tnode *left;
    struct tnode *right;
} TNode;

int main(void) {
    String saludo = "Hola amigos";

    String p, lineptr[MAXLINES], alloc(int);
    int strcmp_(String, String);
    p = (String) malloc(100);

    // padre
    TPointer og = malloc(sizeof(TNode));
    og->word = "bumpit";
    og->count = 1;
    // Nulos
    og->left = og->right = NULL;

    TPointer leftNode = malloc(sizeof(TNode));
    og->word = "alfa";
    og->count = 1;

    // Configuramos el izquierdo
    og->left = leftNode;
}

TPointer talloc(void) {
    return (TPointer) malloc(sizeof(TNode));
}
