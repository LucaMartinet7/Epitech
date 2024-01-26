/*
** EPITECH PROJECT, 2022
** *my_revstr.c
** File description:
** reverce
*/

#include "my.h"

char *my_revstr(char *str)
{
    int length = my_strlen(str);
    int left;
    char tmp;

    for (left = 0; left < length / 2; left++) {
        tmp = str[left];
        str[left] = str[length - left - 1];
        str[length - left - 1] = tmp;
    }
    return str;
}
