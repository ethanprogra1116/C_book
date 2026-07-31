/* Exercise 6-2. Write a program that reads a C program and prints in
 alphabetical order each
 * group of variable names that are identical in the first 6 characters, but
 different somewhere
 * thereafter. Don't count words within strings and comments. Make 6 a parameter
 that can be set
 * from the command line.

 1. hay que implementar argc y argv para el parametro --LISTO
 2. Que el parser ignore strings y comentarios --LISTO desde la funcion getword
 3. Que ignore palabras reservadas --LISTO
 4. que ignore lo que este entre "" o '' -- LISTO
 5. Finalmente imprimir el arbol -- LISTO
 todo terminado

 Hipotesis inicial: Cualquier palabra que no tenga en su inicio o final algun
 simbolo como * o () y que ademas no sea palabra reservada, que no sea
 mayusculas.

 */

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXWORD 100
struct tnode *addtree(struct tnode *, char *);
void make_list(struct tnode *, char *lista[]);
void print_list(char *lista[], int num_char);


int getword(char *, int, bool include_comments, bool inc_strings);

struct tnode {           /* tree node */
    char *word;          /* the word itself */
    int count;           /* number of occurrences */
    struct tnode *left;  /* left subtree */
    struct tnode *right; /* right subtree */
};

// lista de palabras reservadas
char *reserved[] = {"auto",     "break",   "case",   "char",     "const",
                    "continue", "default", "do",     "double",   "else",
                    "enum",     "extern",  "float",  "for",      "goto",
                    "if",       "int",     "long",   "register", "return",
                    "short",    "signed",  "sizeof", "static",   "struct",
                    "switch",   "typedef", "union",  "unsigned", "void",
                    "volatile", "while"};

int main(int argc, char *argv[]) {
    // Checamos si se ha pasado un argumento de linea de comandos
    int num_char; // default
    if (argc > 2 && strcmp("-n", argv[1]) == 0) {
        num_char = atoi(argv[2]);
    } else {
        num_char = 6;
    }

    struct tnode *root;
    char word[MAXWORD];
    root = NULL;
    while (getword(word, MAXWORD, false, false) != EOF) {
        // Ignoramos numeros y caracteres especiales. Solo se aceptan letras
        // root solo cambia una vez al inicio. la asignacion de todos los nodos
        // se hace recursivamente por addtree
        unsigned long len = strlen(word);
        if (isalpha(word[0]) && isalpha(word[len - 1]) && len >= num_char) {
            int n_palabras = sizeof(reserved) / sizeof(reserved[0]);
            // Esto es bruteforce, podria usar un hash table o binsearch en un futuro
            bool is_reserved = false;
            for (int i = 0; i < n_palabras; i++) {
                if (strcmp(word, reserved[i]) == 0) {
                    is_reserved = true;
                    break;
                }
            }

            if (!is_reserved) {
                root = addtree(root, word);
            }
        }
    }

    char *lista[MAXWORD];
    make_list(root, lista);
    print_list(lista, num_char);
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
        p->count++; /* repeated word */

    // In the case this node is not null and is not the word we are searching
    // for, we recursively call addtree on the left or right subtree
    else if (cond < 0) /* less than into left subtree */
        p->left = addtree(p->left, w);
    else /* greater than into right subtree */
        p->right = addtree(p->right, w);
    return p;
}


// Indice global de la lista:
int in_lis = 0;
/* make_list: save the words in order in a char pointer */
void make_list(struct tnode *p, char *lista[]) {
    if (p != NULL) {
        make_list(p->left, lista);
        lista[in_lis++] = p->word; // p->word ya tenia memoria asignada
        make_list(p->right, lista);
    }
}

void print_list(char *strings[], int num_char) {
    // Comprobacion si hay elementos en la lista
    if (in_lis == 0) {
        return;
    }
    char prefix[num_char + 1];
    char temp_pre[num_char + 1];
    char * past_word = *strings;
    int group_num = 1;
    // bool new_group = true;
    int nwords_group = 0;

    // Confiando ciegamente en que la primera palabra son mas de 6 caracteres
    for (short i = 0; i < num_char; i++) {
        prefix[i] = (*strings)[i];
    }
    prefix[num_char] = '\0';

    // ------------ SE REPITE UNA VEZ POR PALABRA ------------
    for (int i = 0; i < in_lis; i++) {

        // Obtain actual word prefix with the length we desire without changing the word
        // in the source which is *lista
        char *x = malloc(strlen(*strings) + 1); // We obtain space
        strcpy(x, *strings); //deep copy
        x[num_char] = '\0';


        // Temp_prefix
        strcpy(temp_pre, x);
        free(x); // No se si este free pueda ponerse hasta despues del for y que x solo reasigne

        if (strcmp(prefix, temp_pre) == 0) {
            nwords_group++;
            if (nwords_group == 2) {
                printf("Grupo %d \n", group_num++);
                printf("Prefijo: %s\n", prefix);
                printf("%s\n", past_word);
                printf("%s\n", *strings); //actual
                // new_group = false;
            } else if (nwords_group > 2) {
                printf("%s\n", *strings);
            }
        } else {
            // new_group = true;
            nwords_group = 1;
            past_word = *strings;
            strcpy(prefix, temp_pre);
        }

        // Next word
        strings++;
    }
}

/* talloc: make a tnode */
struct tnode *talloc(void) {
    // Se hace el cast a un (struct tnode * ) porque malloc devuelve un void *
    return (struct tnode *)malloc(sizeof(struct tnode));
}

// ---------------- YA NO LA PONEMOS PORQUE ES ESTANDAR
// -----------------------------
/* make a duplicate of s */
// char *strdup(char *s) {
//     char *p;
//     p = (char *)malloc(strlen(s) + 1); /* +1 for '\0' */
//     if (p != NULL)
//         strcpy(p, s);
//     return p;
// }
