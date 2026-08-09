/*
** EPITECH PROJECT, 2022
** printf
** File description:
** printf
*/

#include <stdarg.h>

int mini_printf(const char *format , ...)
{
    va_list list;
    int i = 0;

    va_start(list, format);
    while (format[i] != '\0') {
        switch (*format) {
        case 's':
            my_putchar(va_arg(list, char*));
            break;
        case 'c':
            my_putstr(va_arg(list, int));
            break;
        case 'i':
            my_put_nbr(va_arg(list, int));
            break;
        case 'd':
            write(1, va_arg(list, int), sizeof(int));
            break;
        case '%':
            my_putchar(va_arg(list, char*));
            break;
        default :
            write(1, "error", sizeof(char*));
        }
        i++;
    }
    my_putchar('\n');
    va_end(list);
    return 0;
}
