/*
** EPITECH PROJECT, 2022
** printf
** File description:
** printf
*/

#include <stdarg.h>

int my_putstr(char *str);
int my_put_nbr(int nb);
char *my_strcpy(char *dest, char *src);
void my_putchar(char c);

void outplayed(const char *format, int i, va_list list)
{
    switch (format[i]) {
    case 'c':
        my_putchar(va_arg(list, char));
        break;
    case 's':
        my_putstr(va_arg(list, char*));
        break;
    case 'i':
        my_put_nbr(va_arg(list, int));
        break;
    case 'd':
        my_put_nbr(va_arg(list, int));
        break;
    case '%':
        my_putchar('%');
        break;
    }
}

int mini_printf(const char *format, ...)
{
    va_list list;
    int i = 0;
    va_start(list, format);
    while (format[i] != '\0') {
        if (format[i] != '%')
            my_putchar(format[i]);
        else {
            i++;
            outplayed(format, i, list);
        }
        i++;
    }
    va_end(list);
    return 0;
}
