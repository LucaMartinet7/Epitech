/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-2-minishell2-luca.martinet
** File description:
** for_free
*/

#include "../../include/my.h"

void free_env(char **array)
{
    int i = 0;
    for (; array[i] != NULL; i++) {
        free(array[i]);
    }
    free(array);
}
