/*
** EPITECH PROJECT, 2022
** B-CPE-110-PAR-1-2-antman-luca.martinet [WSL: Ubuntu]
** File description:
** my_strlength.c
*/

#include "../include/my_printf.h"

int my_strlength(const char *str)
{
    int i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}
