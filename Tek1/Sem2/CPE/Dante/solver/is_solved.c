/*
** EPITECH PROJECT, 2022
** B-CPE-200-PAR-2-2-dante-noe.kurata
** File description:
** is_solved.c
*/

#include "../include/solver.h"

int is_solve(solver_t *solver, char **maze, char comparator)
{
    if (maze[solver->pos_y][solver->pos_x] == comparator)
        return 1;
    return 0;
}
