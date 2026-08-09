/*
** EPITECH PROJECT, 2022
** strdup
** File description:
** day 8
*/
#include <stdlib.h>

int my_strlen(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        i += 1;
    }
    return (i);
}

char *my_strdup(char const *src)
{
    int i;
    char *str;
    str = malloc(sizeof(char) * (my_strlen(str) + 1));
    for (i = 0; src[i] != '\0'; i++) {
        str[i] = src[i];
    }
    str[i] = '\0';
    return str;
}
