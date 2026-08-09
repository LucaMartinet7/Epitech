/*
** EPITECH PROJECT, 2022
** B-CPE-200-PAR-2-2-dante-noe.kurata
** File description:
** print_map_solve.c
*/

#include "../include/solver.h"

void printer(char num)
{
    if (num == '3')
        printf("o");
    else if (num == '1' || num == '2')
        printf("*");
    else
        printf("X");
}

void print_map_solve(solver_t *solver, char **map)
{
    for (int i = 0; i < solver->height; i++) {
        for (int j = 0; j < solver->width2; j++) {
            printer(map[i][j]);
        }
        putchar('\n');
    }
}
