/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-2-lemin-luca.martinet
** File description:
** check_file
*/

#include "../include/lem.h"
#include "../lib/my/my.h"
#include <stdlib.h>

char **check_file(ant_values_t *ant_values)
{
    ant_values->text = 0;
    ant_values->ant_count = 0;
    ant_values->position = 0;
    ant_values->total_lines = 0;
    ant_values->error_lines = 0;
    ant_values->ant_colony = 0;
    size_t size = 0;
    char *buff = 0;
    char *file = 0;
    int i = 0;
    while (getline(&buff, &size, stdin) != -1) {
        if (i == 0) {
            file = my_strdup(buff);
        } else {
            file = realloc(file, my_strlen(file) + my_strlen(buff) + 1);
            my_strcat(file, buff);
        }
        i = i + 1;
    }
    free(buff);
    if (i == 0) {
        free(file);
        return NULL;
    }
    ant_values->total_lines = i;
    ant_values->str = check_file_data(file, i);
    ant_values->str = check_file_clean(ant_values->str, i);
    free(file);
    return ant_values->str;
}
