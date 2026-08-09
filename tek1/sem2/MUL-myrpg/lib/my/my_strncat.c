/*
** EPITECH PROJECT, 2022
** *my_strncat.c
** File description:
** n cat
*/

#include "my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int temp = my_strlen(dest);
    while (i < nb) {
        dest[temp] = src[i];
        i++;
        temp++;
    }
    dest[temp] = '\0';
    return (dest);
}
