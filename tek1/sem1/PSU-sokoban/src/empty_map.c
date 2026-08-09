/*
** EPITECH PROJECT, 2022
** B-PSU-100-PAR-1-2-sokoban-luca.martinet
** File description:
** empty_map.c
*/

#include "../include/my.h"

void empty_the_map2(soko_t *soko, int i, int j)
{
    if (soko->map_temp[i][j] == 'X')
        soko->map_temp[i][j] = ' ';
    if (soko->map_temp[i][j] == 'P')
        soko->map_temp[i][j] = ' ';
}

void empty_the_map(soko_t *soko)
{
    for (int i = 0; soko->map_temp[i] != NULL; i++) {
        for (int j = 0; soko->map_temp[i][j] != NULL; j++) {
            empty_the_map2(soko, i, j);
        }
    }
}
