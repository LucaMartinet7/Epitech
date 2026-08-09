/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-2-lemin-luca.martinet
** File description:
** check_struct
*/

#include "../include/lem.h"
#include "../lib/my/my.h"

int check_struct(ant_values_t *ant_values)
{
    if (ant_values == 0 || ant_values->ant_colony == 0)
        return 84;
    return 0;
}
