/*
** EPITECH PROJECT, 2022
** B-CPE-200-PAR-2-2-dante-noe.kurata
** File description:
** error_handling.c
*/

#include "../include/solver.h"

int error_handling1(solver_t *solver)
{
    if (solver->raw_maze == NULL) {
        printf("no solution found");
        return 1;
    } if (solver->raw_maze[0] != '*' ||
    solver->raw_maze[strlen(solver->raw_maze) - 1] != '*') {
        printf("no solution found");
        return 1;
    } if (solver->raw_maze[0] == '\0') {
        printf("no solution found");
        return 1;
    }
    return 0;
}
