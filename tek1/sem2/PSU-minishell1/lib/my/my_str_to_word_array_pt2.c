/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-2-minishell1-luca.martinet
** File description:
** my_str_to_word_array_pt2
*/

#include "../../include/my.h"

void *check_malloc(char **array, int *columns)
{
    if (array == NULL || columns == NULL) {
        free(columns);
        free(array);
        return NULL;
    }
    return array;
}
