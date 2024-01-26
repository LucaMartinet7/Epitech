/*
** EPITECH PROJECT, 2022
** B-CPE-200-PAR-2-2-dante-noe.kurata
** File description:
** solve_maze.c
*/

#include "../include/solver.h"


char **up_left(solver_t *solver, char **maze, int x, int y)
{
    if (x - 1 >= 0 && maze[y][x - 1] == '1') {
        if (is_solve(solver, maze, '2') == 1)
            return maze;
        explore(solver, maze, y, x - 1);
    }
    if (y - 1 >= 0 && maze[y - 1][x] == '1') {
        if (is_solve(solver, maze, '2') == 1)
            return maze;
        explore(solver, maze, y - 1, x);
    }
    return maze;
}

char **up_left2(solver_t *solver, char **maze, int x, int y)
{
    if (x - 1 >= 0 && maze[y][x - 1] == '2') {
        if (is_solve(solver, maze, '3') == 1)
            return maze;
        explorer_pt2(solver, maze, y, x - 1);
    } if (y - 1 >= 0 && maze[y - 1][x] == '2') {
        if (is_solve(solver, maze, '3') == 1)
            return maze;
        explorer_pt2(solver, maze, y - 1, x);
    }
    return maze;
}

char **explorer_pt2(solver_t *solver, char **maze, int y, int x)
{
    maze[y][x] = '3';
    if (is_solve(solver, maze, '3') == 1)
        return maze;
    if (y + 1 <= solver->pos_y && maze[y + 1][x] == '2') {
        if (is_solve(solver, maze, '3') == 1)
            return maze;
        explorer_pt2(solver, maze, y + 1, x);
    } if (x + 1 <= solver->pos_x && maze[y][x + 1] == '2') {
        if (is_solve(solver, maze, '3') == 1)
            return maze;
        explorer_pt2(solver, maze, y, x + 1);
    }
    maze = up_left2(solver, maze, x, y);
    return maze;
}

char **explore(solver_t *solver, char **maze, int y, int x)
{
    maze[y][x] = '2';
    if (is_solve(solver, maze, '2') == 1)
        return maze;
    if (x + 1 <= solver->pos_x && maze[y][x + 1] == '1') {
        if (is_solve(solver, maze, '2') == 1)
            return maze;
        explore(solver, maze, y, x + 1);
    } if (y + 1 <= solver->pos_y && maze[y + 1][x] == '1') {
        if (is_solve(solver, maze, '2') == 1)
            return maze;
        explore(solver, maze, y + 1, x);
    }
    maze = up_left(solver, maze, x, y);
    return maze;
}

char **solve_maze(solver_t *solver, char **maze_in_numbers)
{
    solver->pos_x = solver->width2 - 1;
    solver->pos_y = solver->height - 1;
    maze_in_numbers = explorer_pt2(solver,
    explore(solver, maze_in_numbers, 0, 0), 0, 0);
    return maze_in_numbers;
}
