/*
** EPITECH PROJECT, 2022
** B-MUL-100-PAR-1-2-myradar-noe.kurata
** File description:
** str2linearray.c
*/

#include "../include/my_printf.h"

int countcolumns(char *str, int n)
{
    int i = 1;

    while (str[i + n] != '\n' && str[i + n] != '\0')
        i += 1;
    return i;
}

char **my_str2linearray(char *str, int n)
{
    char **tab = malloc(sizeof(char) * (n + 1));
    int i = 0;
    int j;
    int k = 0;

    while (i < n) {
        j = 0;
        tab[i] = malloc(sizeof(char) * (countcolumns(str, k) + 1));
        while (str[k] != '\n' && str[k] != '\0') {
            tab[i][j] = str[k];
            j++;
            k++;
        }
        tab[i][j] = '\0';
        i++;
        k++;
    }
    tab[i] = NULL;
    return tab;
}
