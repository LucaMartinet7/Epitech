/*
** EPITECH PROJECT, 2023
** B-CPE-110-PAR-1-2-antman-luca.martinet
** File description:
** my_strncpy.c
*/

#include "../include/my_printf.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int i;
    for (i = 0; i <= n; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}
