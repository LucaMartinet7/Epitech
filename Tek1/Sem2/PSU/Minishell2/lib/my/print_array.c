/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-2-minishell2-luca.martinet
** File description:
** print_array
*/

#include "../../include/my.h"

void print_array_single(char **array)
{
    for (int i = 0; array[i] != NULL; i++) {
        for (int j = 0; array[i][j] != '\0'; j++) {
            my_printf("%c", array[i][j]);
        }
    }
    my_printf("\n");
}
