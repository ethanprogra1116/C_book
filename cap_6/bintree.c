// El objetivo de este programa es tener el recuento de palabras en un stream
// sin saber de antemano que palabras habran, como no podemos acomodarlas
// o mas bien seria costoso computacionalmente lo guardaremos en un Arbol
// Binario
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAXWORD 100
struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int, int comments);

struct tnode {           /* tree node */
    char *word;          /* the word itself */
    int count;           /* number of occurrences */
    struct tnode *left;  /* left subtree */
    struct tnode *right; /* right subtree */
};

int main(void) {
    struct tnode *root;
    char word[MAXWORD];
    root = NULL;
    while (getword(word, MAXWORD, false) != EOF)
        if (isalpha(word[0])) // Ignoramos numeros y caracteres especiales. Solo se aceptan letras
          // root solo cambia una vez al inicio. la asignacion de todos los nodos
          // se hace recursivamente por addtree
          root = addtree(root, word);

    treeprint(root);
    return 0;
}

// Routine that sets space for a new node
struct tnode *talloc(void);
char *strdup(const char *); // en la que implementa el libro es sin el const
/* addtree: add a node with w, at or below p */
struct tnode *addtree(struct tnode *p, char *w) {
    int cond;
    if (p == NULL) {  /* a new word has arrived */
        p = talloc(); /* make a new node */
        p->word = strdup(w);
        p->count = 1;
        p->left = p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) == 0)
        p->count++;    /* repeated word */

    // In the case this node is not null and is not the word we are searching for,
    // we recursively call addtree on the left or right subtree
    else if (cond < 0) /* less than into left subtree */
        p->left = addtree(p->left, w);
    else /* greater than into right subtree */
        p->right = addtree(p->right, w);
    return p;
}

/* treeprint: in-order print of tree p */
void treeprint(struct tnode *p) {
    if (p != NULL) {
        treeprint(p->left);
        printf("%4d %s\n", p->count, p->word);
        treeprint(p->right);
    }
}

/* talloc: make a tnode */
struct tnode *talloc(void) {
  // Se hace el cast a un (struct tnode * ) porque malloc devuelve un void *
  return (struct tnode *) malloc(sizeof(struct tnode));
}

// ---------------- YA NO LA PONEMOS PORQUE ES ESTANDAR -----------------------------
/* make a duplicate of s */
// char *strdup(char *s) {
//     char *p;
//     p = (char *)malloc(strlen(s) + 1); /* +1 for '\0' */
//     if (p != NULL)
//         strcpy(p, s);
//     return p;
// }
