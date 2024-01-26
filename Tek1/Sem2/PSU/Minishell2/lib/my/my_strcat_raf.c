/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-2-minishell2-luca.martinet
** File description:
** my_strcat_raf
*/

#include "../../include/my.h"

char *my_cat_raf(char *src1, char *src2)
{
    int i;
    char *dest = malloc(sizeof(char) * (my_strlen(src1) + my_strlen(src2) + 1));
    if (dest == NULL)
        return NULL;
    for (i = 0; src1[i] != '\0'; i++)
        dest[i] = src1[i];
    for (int j = 0; src2[j] != '\0'; j++, i++) {
        dest[i] = src2[j];
        i++;
    }
    dest[i] = '\0';
    return dest;
    free(dest);
}
