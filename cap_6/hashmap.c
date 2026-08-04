/*
 * CODIGO DE K & R en el que se elabora un hashmap
 * estructuras de datos: hashmap
 * strcust importantes: nlist
 * funciones importantes: lookup(s), install(s, t)


 Explicación: Tenemos un array de punteros a strcut nlist.
 el struct tiene dos punteros a cadenas. el nombre y la definicion asi como un
 puntero a otro struct si es que dos elementos estan en esa posicion del hashmap
 */

#include <stdlib.h>
#include <string.h>
#define HASHSIZE 101
static struct nlist *hashtab[HASHSIZE]; /* pointer table */
struct nlist *lookup(char *);
char *strdup(char *);

struct nlist {          /* table entry: */
    struct nlist *next; /* next entry in chain */
    char *name;         /* defined name alias key*/
    char *defn;         /* replacement text alias value*/
};

/* hash: form hash value for string s */
unsigned hash(char *s) {
    // Necesitamos unsigned para devolver indices no negativos y
    // para que el overflow este definido
    // Una misma palabra siempre va a producir un mismo hash
    unsigned hashval;
    for (hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}

/* lookup: look for s in hashtab */
struct nlist *lookup(char *s) {
    struct nlist *np;
    // Ubicamos un índice. Si no es esa palabra buscamos en la siguiente del
    // index hasta que pase una de dos cosas. Lo encontramos o es NULL
    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
        if (strcmp(s, np->name) == 0)
            return np; /* found */
    return NULL;       /* not found */
}

/* install: put (name, defn) in hashtab */
struct nlist *install(char *name, char *defn) {
    struct nlist *np;
    unsigned hashval;
    if ((np = lookup(name)) == NULL) {            /* not found */
        np = (struct nlist *)malloc(sizeof(*np)); // reservamos espacio
        // Comprobamos si se pudo reservar espacio
        if (np == NULL || (np->name = strdup(name)) == NULL)
            return NULL;
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    } else                      /* already there */
        free((void *)np->defn); /*free previous defn */
    if ((np->defn = strdup(defn)) == NULL)
        return NULL;
    return np;
}

/*undef: remove a name and definition from the table mantained by lookup and
 * install */
void undef(char *s) {
    // Me van a devolver el np y de ahi tengo que buscar la entrada
    struct nlist *np = lookup(s);
    unsigned hashpos = hash(s);
    if (np != NULL) {
        // Primer caso en la lista
        if (np == hashtab[hashpos]) {
            hashtab[hashpos] = np->next;
            free((void *)np->name);
            free((void *)np->defn);
            free(np);
        } else {
            // Conectamos el de la posicion pasada con el siguiente
            struct nlist *prev;
            np = hashtab[hashpos];
            while (np != NULL) {
                if (strcmp(np->name, s) == 0) {
                    prev->next = np->next;
                    // Liberamos espacio
                    free(np->name);
                    free(np->defn);
                    free(np);
                    break;
                }
                prev = np;
                np = np->next;
            }
        }
    }
}

int main(void) { return 0; }
