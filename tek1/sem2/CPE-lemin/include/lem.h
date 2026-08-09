/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-2-lemin-luca.martinet
** File description:
** lem
*/

#ifndef LEM_H_
#define LEM_H_
    #include <stdio.h>

typedef struct anthill_s
{
    char *start;
    char **rooms;
    char **tunnels;
    char *end;
    int nb_ant;
} anthill_t;

typedef struct ant_values_s {
    char **text;
    int ant_count;
    int position;
    int total_lines;
    int error_lines;
    char **str;
    anthill_t *ant_colony;
} ant_values_t;

int help(void);
int entry_point(ant_values_t *ant_values);
int check_struct(ant_values_t *ant_values);
char **check_file(ant_values_t *ant_values);
char **check_file_data(char *file, int lines);
char **check_file_clean(char **buff, int lines);
void remove_hashtag(ant_values_t *ant_values);

#endif /* !LEM_H_ */
