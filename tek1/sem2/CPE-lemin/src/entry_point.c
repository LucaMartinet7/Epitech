/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-2-lemin-luca.martinet
** File description:
** entry_point
*/

#include "../include/lem.h"
#include "../lib/my/my.h"
#include <unistd.h>

int entry_point(ant_values_t *ant_values)
{
    ant_values->str = check_file(ant_values);
    if (ant_values->str == 0)
        return 84;
    remove_hashtag(ant_values);
    write(1, "#number_of_ants\n", 16);
    return 0;
}
