/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-2-lemin-luca.martinet
** File description:
** my_strdup
*/

#include "my.h"
#include <stdlib.h>

char *my_strdup(const char *str)
{
    int len = my_strlen(str);
    char *result = malloc(len + 1);
    for (int i = 0; i <= len; i = i + 1)
        result[i] = str[i];
    return result;
}
