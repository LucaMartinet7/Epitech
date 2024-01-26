/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-2-lemin-luca.martinet
** File description:
** main
*/

#include "../include/lem.h"
#include "../lib/my/my.h"
#include <stdlib.h>
#include <unistd.h>

int main(int ac, char **av)
{
    ant_values_t *ant_values = malloc(sizeof(ant_values_t));
    ant_values->ant_colony = malloc(sizeof(ant_values->ant_colony));
    if (check_struct(ant_values) != 0) {
        return 84;
    }
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        return (help());
    }
    if (ac != 1) {
        write(2, "Error: invalid number of arguments\n", 36);
        return 84;
    }
    entry_point(ant_values);
    return 0;
}
