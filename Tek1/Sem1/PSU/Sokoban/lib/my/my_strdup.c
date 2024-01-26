/*
** EPITECH PROJECT, 2022
** B-PSU-100-PAR-1-2-myls-luca.martinet
** File description:
** my_strdup.c
*/

#include <stdio.h>
#include "../../include/my.h"

char *my_strdup(const char *str)
{
    int len = my_strlen(str);
    char *result = malloc(len + 1);
    for (int i = 0; i <= len; i++)
        result[i] = str[i];
    return result;
}
