/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-2-minishell1-luca.martinet
** File description:
** my_str_array_dup
*/

#include "../../include/my.h"

static int count_columns(char **array)
{
    int col = 0;

    for (int i = 0; array[i] != 0; i++) {
        col++;
    }
    return col;
}

char **my_str_array_dup(char **array_cpy)
{
    int counter = count_columns(array_cpy);
    char **array = malloc(sizeof(char *) * counter + 1);

    if (array == NULL)
        return NULL;
    for (int i = 0; array[i] != NULL; i++) {
        array[i] = malloc(sizeof(char) * my_strlen(array[i] + 1));
        for (int j = 0; array[i][j] != '\0'; j++) {
            array[i][j] = array_cpy[i][j];
        array[i][my_strlen(array[i])] = '\0';
        }
    }
    array[counter] = NULL;
    return array;
    for_free(array);
}
