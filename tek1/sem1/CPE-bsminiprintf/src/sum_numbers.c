/*
** EPITECH PROJECT, 2022
** num
** File description:
** num
*/

#include <stdarg.h>
#include "../include/bsprintf.h"

int sum_numbers(int n, ...)
{
    va_list ap;
    int i = 0;
    int ret = 0;

    va_start(ap, n);
    while (i < n) {
        ret = ret + va_arg(ap, int);
        i++;
    }
    va_end(ap);
    return ret;
}
