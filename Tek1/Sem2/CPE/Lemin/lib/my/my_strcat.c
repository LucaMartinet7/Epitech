/*
** EPITECH PROJECT, 2022
** *my_strcat.c
** File description:
** cat
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int temp = my_strlen(dest);
    while (src[i] != '\0') {
        dest[temp] = src[i];
        i++;
        temp++;
    }
    dest[temp] = '\0';
    return (dest);
}
