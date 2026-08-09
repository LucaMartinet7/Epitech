/*
** EPITECH PROJECT, 2022
** stdarg
** File description:
** stdarg
*/

#include <stdarg.h>
#include "../include/bsprintf.h"
#include "../include/my.h"

void disp_stdarg(char *s, ...)
{
    va_list ap;
    int i = 0;

    va_start(ap, s);
    while(s[i] != '\0') {
        switch (*s) {
        case 'c':
            my_putchar(va_arg(ap, char*));
            break;
        case 's':
            my_putstr(va_arg(ap, char*));
            break;
        case 'i':
            my_put_nbr(va_arg(ap, int));
            break;
        }
        my_putchar('\n');
        i++;
    }
    va_end(ap);
    return 0;
}
