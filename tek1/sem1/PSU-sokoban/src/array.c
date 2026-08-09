/*
** EPITECH PROJECT, 2022
** B-PSU-100-PAR-1-2-sokoban-luca.martinet
** File description:
** array.c
*/

#include "../include/my.h"

char **malloc_array(soko_t *soko)
{
    char **array = malloc(sizeof(char *) * (soko->lines + 1));
    if (array == NULL)
        return NULL;
    for (int i = 0; i < soko->lines; i++) {
        array[i] = malloc(sizeof(char) * (soko->columns + 1));
        if (array[i] == NULL)
            return NULL;
    }
    return array;
}

char **map_in_array(soko_t *soko)
{
    count_lines(soko);
    count_columns(soko);
    char **array = malloc_array(soko);
    int k = 0;
    for (int i = 0; i < soko->lines; i++) {
        for (int j = 0; j < soko->columns; j++) {
            array[i][j] = soko->buf[k];
            k++;
        }
        k++;
    }
    return array;
}

void find_player2(soko_t *soko, int i, int j)
{
    if (soko->map_temp[i][j] == 'P') {
        soko->x = i;
        soko->y = j;
    }
}

void find_player(soko_t *soko)
{
    for (int i = 0; soko->map[i] != NULL; i++) {
        for (int j = 0; soko->map[i][j] != NULL; j++) {
            find_player2(soko, i, j);
        }
    }
}

int map_to_doulbe_char(soko_t *soko)
{
    soko->map_temp = map_in_array(soko);
    soko->map = map_in_array(soko);
    find_player(soko);
    if (soko->x == 0 || soko->y == 0)
        return 84;
    soko->save_x = soko->x;
    soko->save_y = soko->y;
    empty_the_map(soko);
    return 0;
}
