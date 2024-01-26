/*
** EPITECH PROJECT, 2022
** B-CPE-200-PAR-2-2-dante-noe.kurata
** File description:
** main.c
*/

#include "../include/solver.h"

void free_for(char **maze_numbers, solver_t *solver)
{
    for (int j = 0; j < solver->height; j++)
        free(maze_numbers[j]);
    free(maze_numbers);
}

void free_all(solver_t *solver, char **maze_numbers)
{
    free(solver->raw_maze);
    free_for(maze_numbers, solver);
}

int solver_steps(char **av)
{
    solver_t solver = {0};
    solver.raw_maze = open_file(av[1]);

    if (error_handling1(&(solver)))
        return 84;
    count_height(&(solver));
    count_width(&(solver));
    char **char_maze = maze_to_array(&(solver), malloc_maze(&(solver)));
    char_maze = maze_in_numbers(&(solver), char_maze);
    char_maze = solve_maze(&(solver), char_maze);
    print_map_solve(&(solver), char_maze);
    free_all(&(solver), char_maze);
    return 0;
}

int main(int ac, char **av)
{
    if (ac != 2 || !av || !av[1])
        return 84;
    if (ac == 2)
        solver_steps(av);
    return 0;
}
