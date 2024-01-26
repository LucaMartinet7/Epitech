/*
** EPITECH PROJECT, 2022
** B-BOO-101-PAR-1-1-phoenixd02-noe.kurata
** File description:
** my_strstr.c
*/

#include "../include/my_printf.h"

int my_strcmp(char const *s1, char const *s2)
{
    for (int i = 0; s2[i] != '\0' ; i++) {
        if (s1[i] < s2[i])
            return -1;
        if (s1[i] > s2[i])
            return 1;
    }
    return 0;
}

char *my_strstr(char *str, char const *to_find)
{
    if (to_find == NULL)
        return str;
    for (int i = 0; str[i] != '\0'; i++) {
        if (my_strcmp(str + i, to_find) == 0)
            return str + i;
    }
    return NULL;
}
