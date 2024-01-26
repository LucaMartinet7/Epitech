/*
** EPITECH PROJECT, 2023
** B-SYN-200-PAR-2-1-FASTAtools-luca.martinet
** File description:
** revstr
*/

#include <string.h>
#include <stdlib.h>
#include "../include/fast.h"

char capitalize(char c)
{
    if (c >= 'a' && c <= 'z')
        c -= 32;
    return c;
}

char *revstr(char *str)
{
    char *cpy = NULL;
    int i = 0;
    int len = strlen(str) - 1;

    if ((cpy = malloc(sizeof(char) * (len + 2))) == NULL)
        return (NULL);
    while (str[i]) {
        cpy[i] = str[len];
        len--;
        i++;
    }
    cpy[i] = '\0';
    return (cpy);
}
