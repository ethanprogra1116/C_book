#include <stdio.h>

int day_of_year(int year, int month, int day);
int day_of_year_pointers(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);
void month_day_pointers(int year, int yearday, int *pmonth, int *pday);

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

// static char daytabs[2][17] = {
//     "si",
//     "Yo estoy muy bien"
// };

int main(void) {
    // printf("%s\n", daytabs[0]);
    // printf("%s\n", daytabs[1]);
    int dia_del_año = day_of_year(2026, 05, 16);
    int dia_del_año_punteros = day_of_year_pointers(2026, 05, 16);
    printf("El dia 16 de mayo del 2026 es el dia %d\n", dia_del_año);
    printf("El dia 16 de mayo del 2026 es el dia %d con punteros\n",
           dia_del_año_punteros);

    int month, day;
    month_day(2026, 300, &month, &day);
    printf("El dia 300 del año 2026 es el mes %d dia %d\n", month, day);

    return 0;
}

/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day) {
    if (month > 12 || month <= 0 || day > 365 || day <= 0) {
        printf("Fecha no valida");
        return -1;
    }

    int i, leap;
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    for (i = 1; i < month; i++)
        day += daytab[leap][i];
    return day;
}

int day_of_year_pointers(int year, int month, int day) {
    int i, leap;
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

    if (month > 12 || month <= 0 || day > (leap ? 366 : 365) || day <= 0) {
        printf("Fecha no valida");
        return -1;
    }

    for (i = 1; i < month; i++)
        day += *(*(daytab + leap) + i);
    return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday) {
    int i, leap;
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

    if (yearday < 1 || yearday > (leap ? 366 : 355) ) {
        printf("Fecha invalida");
        return;
    }

    for (i = 1; yearday > daytab[leap][i]; i++) {
        yearday -= daytab[leap][i];
    }

    *pmonth = i;
    *pday = yearday;
}

void month_day_pointers(int year, int yearday, int *pmonth, int *pday) {
    int i, leap;
    int p;
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

    if (yearday < 1 || yearday > (leap ? 366 : 355) ) {
        printf("Fecha invalida");
        return;
    }

    // for (i = 1; yearday > daytab[leap][i]; i++) {
    //     yearday -= daytab[leap][i];
    // }


    for (i = 1; yearday > (*(*(daytab + leap) + i)); i++) {
        yearday -= *(*(daytab + leap) + i);
    }

    *pmonth = i;
    *pday = yearday;
}

/* month_name: return name of n-th month */
// Similar a la declaracion
char *nombre = "Jorge Ethan Mc Kelligan Desilos";
char *month_name(int n) {
    static char *name[] = {"Illegal month", "January",   "February", "March",
                           "April",         "May",       "June",     "July",
                           "August",        "September", "October",  "November",
                           "December"};
    return (n < 1 || n > 12) ? name[0] : name[n];
}
