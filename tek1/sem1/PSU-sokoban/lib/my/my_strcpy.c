/*
** EPITECH PROJECT, 2022
** B-PSU-100-PAR-1-2-sokoban-luca.martinet
** File description:
** my_strcpy.c
*/

#include "../../include/my.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;
    dest = malloc(sizeof(char) * my_strlen(src) + 1);
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
