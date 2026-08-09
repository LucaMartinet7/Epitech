/*
** EPITECH PROJECT, 2023
** B-SYN-200-PAR-2-1-calendar-luca.martinet
** File description:
** str_warry_sep
*/

#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "calendar.h"

int nb_cols(char *str, char c)
{
    int i = 0;

    while (str[i] != '\0' && str[i] != c)
        i++;
    return (i);
}

int nb_word(char *str, char c)
{
    int i = 0;
    int count = 1;

    while (str[i] != '\0') {
        if (str[i] == c)
            count++;
        i++;
    }
    return (count);
}

char **extra_func(char **dest, char *str, char c, int j)
{
    while (str[0] == c || str[0] == '\t')
        str++;
    dest[j] = malloc(sizeof(char) * (nb_cols(str, c) + 1));
    return (dest);
}

char **strwarr(char *str, char c)
{
    int j = 0, k = 0;
    char **dest = malloc(sizeof(char *) * (nb_word(str, c) + 1));

    dest[j] = malloc(sizeof(char) * (nb_cols(str, c) + 1));
    while (str[0] != '\0') {
        if (str[0] == c || str[0] == '\t') {
            dest[j++][k] = '\0';
            k = 0;
            dest = extra_func(dest, str, c, j);
        }
        if (str[0] != '\0' && str[0] != c)
            dest[j][k++] = str[0];
        str++;
    }
    dest[j][k] = '\0';
    dest[j + 1] = NULL;
    return (dest);
}
