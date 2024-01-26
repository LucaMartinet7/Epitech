/*
** EPITECH PROJECT, 2022
** B-PSU-100-PAR-1-2-myls-luca.martinet
** File description:
** my_strdup.c
*/

#include "../../include/my.h"

char *my_strdup(char const *src)
{
    char *str;
    int i = 0;
    str = malloc(sizeof(char) * (my_strlen(src) + 1));
    if (str == NULL)
        return NULL;
    for (; src[i] != '\0'; i++){
        str[i] = src[i];
    }
    str[i] = '\0';
    return str;
    free(str);
}
