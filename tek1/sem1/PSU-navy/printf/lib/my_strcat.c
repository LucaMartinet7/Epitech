/*
** EPITECH PROJECT, 2022
** hello
** File description:
** hello
*/

#include "../include/my_printf.h"

char *my_strcat(char *dest, char const *src)
{
    int z;
    int str = my_strlength(dest);
    for (z = 0; src[z] != '\0'; z++){
        dest[str + z] = src[z];
    }
    dest[str + z] = '\0';
    return (dest);
}
