/*
** EPITECH PROJECT, 2022
** B-CPE-200-PAR-2-2-dante-noe.kurata
** File description:
** print_arrays.c
*/

#include "../include/solver.h"

void print_array(solver_t *solver, char **map)
{
    for (int i = 0; i < solver->height; i++) {
        for (int j = 0; j < solver->width2; j++) {
            printf("%c", map[i][j]);
        }
        putchar('\n');
    }
}
