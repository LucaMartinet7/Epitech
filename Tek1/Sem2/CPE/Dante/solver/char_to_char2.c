/*
** EPITECH PROJECT, 2022
** B-CPE-200-PAR-2-2-dante-noe.kurata
** File description:
** char_to_char2.c
*/

#include "../include/solver.h"

char **malloc_maze(solver_t *solver)
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

char **maze_to_array(solver_t *solver, char **maze)
{
    int x = 0;
    for (int i = 0; i < solver->height; i++) {
        for (int j = 0; j < solver->width2; j++) {
            maze[i][j] = solver->raw_maze[x];
            x++;
        }
        x++;
    }
    return maze;
}
