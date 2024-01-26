/*
** EPITECH PROJECT, 2022
** B-CPE-200-PAR-2-2-dante-noe.kurata
** File description:
** array_to_numbers.c
*/

#include "../include/solver.h"

void print_array_num_char(solver_t *solver, char **str)
{
    for (int i = 0; i < solver->height; i++) {
        for (int j = 0; j < solver->width2; j++) {
            putchar(str[i][j]);
        }
        putchar('\n');
    }
}

char **malloc_array_numbers(solver_t *solver)
{
    char **array = malloc(sizeof(int *) * (solver->height));

    if (array == NULL)
        return NULL;
    for (int i = 0; i < solver->height; i++) {
        array[i] = malloc(sizeof(int) * (solver->width2));
        if (array[i] == NULL)
            return NULL;
    }
    return array;
}

void options(char **str, int i, int j)
{
    if (str[i][j] == '*')
        str[i][j] = '1';
    if (str[i][j] == 'X')
        str[i][j] = '0';
}

char **maze_in_numbers(solver_t *solver, char **str)
{
    for (int i = 0; i < solver->height; i++) {
        for (int j = 0; j < solver->width2; j++) {
            options(str, i, j);
        }
    }
    return str;
}
