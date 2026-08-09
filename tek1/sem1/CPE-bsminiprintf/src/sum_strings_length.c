/*
** EPITECH PROJECT, 2022
** length string
** File description:
** length string
*/

#include <stdarg.h>
#include "../include/bsprintf.h"
#include "../include/my.h"

int sum_strings_length(int n, ...)
{
    va_list list;
    int length = 0;

    va_start(list, n);
    for (int i = 0; i < n; i++) {
        length = length + my_strlen(va_arg(list, char*));
    }
    va_end(list);
    return length;
}
