/*
** EPITECH PROJECT, 2022
** B-BOO-101-PAR-1-1-phoenixd01-noe.kurata
** File description:
** task05.c
*/

#include "../include/my_printf.h"


char *reverse_string(char *str)
{
    char temp;
    int end = my_strlength(str) - 1;
    for (int i = 0; i < (end / 2) ; i++) {
        temp = str[i];
        str[i] = str[end - i];
        str[end - i] = temp;
    }
    return str;
}
