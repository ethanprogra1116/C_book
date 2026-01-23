#define MAXLINES 5000    /* max #lines to be sorted */
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void qsorts(char *lineptr[], int left, int right);


#define MAXLEN 1000 /* max length of any input line */
static int get_line(char *, int);
