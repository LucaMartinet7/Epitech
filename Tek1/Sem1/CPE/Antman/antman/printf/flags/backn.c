/*
** EPITECH PROJECT, 2022
** %n
** File description:
** %n
*/
#include "../include/my_printf.h"

int backn(char *str)
{
    int i = 0;
    while (str[i] != '%' && str[i + 1] != 'n') {
        i++;
    }
    show_number(i);
    return i;
}
