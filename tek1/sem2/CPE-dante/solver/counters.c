/*
** EPITECH PROJECT, 2022
** B-CPE-200-PAR-2-2-dante-noe.kurata
** File description:
** counters.c
*/

#include "../include/solver.h"

void count_height(solver_t *solver)
{
    int height = 0;
    for (int i = 0; solver->raw_maze[i] != '\0'; i++) {
        if (solver->raw_maze[i] == '\n')
            height++;
    }
    solver->height = height + 1;
}

void count_width(solver_t *solver)
{
    int i = 0;
    while (solver->raw_maze[i] != '\n') {
        i++;
    }
    i++;
    int col = 0;
    while (solver->raw_maze[i] != '\n') {
        col++;
        i++;
    }
    solver->width2 = col;
}
