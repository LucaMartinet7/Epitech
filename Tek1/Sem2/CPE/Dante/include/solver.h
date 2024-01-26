/*
** EPITECH PROJECT, 2022
** B-CPE-200-PAR-2-2-dante-noe.kurata
** File description:
** solver.h
*/

#ifndef SOLVER_H_
    #define SOLVER_H_
    #include "my.h"

typedef struct solver_s{
    char **maze;
    char *raw_maze;
    int height;
    int width2;
    int pos_x;
    int pos_y;
} solver_t;

//open_file
char *open_file(char const *filepath);
//algo
char **solve_maze(solver_t *solver, char **maze_in_numbers);
char **explore(solver_t *solver, char **maze, int y, int x);
char **explorer_pt2(solver_t *solver, char **maze, int y, int x);
int is_solve(solver_t *solver, char **maze, char comparator);
void printer(char num);
//counters
void count_width(solver_t *solver);
void count_height(solver_t *solver);
//array
char **malloc_maze(solver_t *solver);
char **maze_to_array(solver_t *solver, char **maze);
char **malloc_array_numbers(solver_t *solver);
char **maze_in_numbers(solver_t *solver, char **str);
//error_handling
int error_handling1(solver_t *solver);
//print_array
void print_array(solver_t *solver, char **map);
void print_array_num_char(solver_t *solver, char **str);
void print_map_solve(solver_t *solver, char **map);

#endif /* !SOLVER_H_ */
