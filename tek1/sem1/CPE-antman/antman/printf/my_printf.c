/*
** EPITECH PROJECT, 2022
** print
** File description:
** print
*/

#include "include/my_printf.h"

int cases(const char *format, int i, va_list list)
{
    switch (format[i]) {
    case 'd': show_number(va_arg(list, int)); break;
    case 'i': show_number(va_arg(list, int)); break;
    case 's': show_string(va_arg(list, char*)); break;
    case 'c': my_putchar(va_arg(list, int)); break;
    case '%': my_putchar('%'); break;
    case 'b': int_2_bin(va_arg(list, int)); break;
    case 'o': int_2_oct(va_arg(list, int)); break;
    case 'u': uns_dec(va_arg(list, int)); break;
    case 'x': show_string(hex_min(va_arg(list, int))); break;
    case 'X': show_string(hex_maj(va_arg(list, int))); break;
    case 'p': show_string("0x"); show_string(hex_min(va_arg(list, int))); break;
    case 'n': backn(format); break;
    }
}

int my_printf(const char *restrict forma, ...)
{
    va_list list;
    va_start(list, forma);
    for (int i = 0; forma[i] != '\0'; i++) {
        if (forma[i] == '%') {
            i++;
            cases(forma, i, list);
        } else {
            my_putchar(forma[i]);
        }
    }
    return 0;
}
