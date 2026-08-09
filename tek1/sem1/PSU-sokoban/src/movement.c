/*
** EPITECH PROJECT, 2022
** B-PSU-100-PAR-1-2-sokoban-luca.martinet
** File description:
** movement.c
*/

#include "../include/my.h"

void move_up(soko_t *soko)
{
    int x = soko->x;
    int y = soko->y;
    if (soko->map[x - 1][y] == ' ' || soko->map[x - 1][y] == 'O') {
        soko->map[x][y] = soko->map_temp[x][y];
        soko->x -= 1;
        x -= 1;
        soko->map[x][y] = 'P';
    } else if ((soko->map[x - 1][y] == 'X' && soko->map[x - 2][y] == ' ') ||
    (soko->map[x - 1][y] == 'X' && soko->map[x - 2][y] == 'O')) {
        soko->map[x][y] = soko->map_temp[x][y];
        soko->x -= 1;
        x -= 1;
        soko->map[x][y] = 'P';
        soko->map[x - 1][y] = 'X';
    }
}

void move_down(soko_t *soko)
{
    int x = soko->x;
    int y = soko->y;
    if (soko->map[x + 1][y] == ' ' || soko->map[x + 1][y] == 'O') {
        soko->map[x][y] = soko->map_temp[x][y];
        soko->x += 1;
        x += 1;
        soko->map[x][y] = 'P';
    } else if ((soko->map[x + 1][y] == 'X' && soko->map[x + 2][y] == ' ') ||
    (soko->map[x + 1][y] == 'X' && soko->map[x + 2][y] == 'O')) {
        soko->map[x][y] = soko->map_temp[x][y];
        soko->x += 1;
        x += 1;
        soko->map[x][y] = 'P';
        soko->map[x + 1][y] = 'X';
    }
}

void move_left(soko_t *soko)
{
    int x = soko->x;
    int y = soko->y;
    if (soko->map[x][y - 1] == ' ' || soko->map[x][y - 1] == 'O') {
        soko->map[x][y] = soko->map_temp[x][y];
        soko->y -= 1;
        y -= 1;
        soko->map[x][y] = 'P';
    } else if ((soko->map[x][y - 1] == 'X' && soko->map[x][y - 2] == ' ') ||
    (soko->map[x][y - 1] == 'X' && soko->map[x][y - 2] == 'O')) {
        soko->map[x][y] = soko->map_temp[x][y];
        soko->y -= 1;
        y -= 1;
        soko->map[x][y] = 'P';
        soko->map[x][y - 1] = 'X';
    }
}

void move_right(soko_t *soko)
{
    int x = soko->x;
    int y = soko->y;
    if (soko->map[x][y + 1] == ' ' || soko->map[x][y + 1] == 'O') {
        soko->map[x][y] = soko->map_temp[x][y];
        soko->y += 1;
        y += 1;
        soko->map[x][y] = 'P';
    } else if ((soko->map[x][y + 1] == 'X' && soko->map[x][y + 2] == ' ') ||
    (soko->map[x][y + 1] == 'X' && soko->map[x][y + 2] == 'O')) {
        soko->map[x][y] = soko->map_temp[x][y];
        soko->y += 1;
        y += 1;
        soko->map[x][y] = 'P';
        soko->map[x][y + 1] = 'X';
    }
}

void cases(soko_t *soko, int key)
{
    switch (key) {
        case 65:
            if (soko->map[soko->x - 1][soko->y] != '#')
                move_up(soko); break;
        case 66:
            if (soko->map[soko->x + 1][soko->y] != '#')
                move_down(soko); break;
        case 68:
            if (soko->map[soko->x][soko->y - 1] != '#')
                move_left(soko); break;
        case 67:
            if (soko->map[soko->x][soko->y + 1] != '#')
                move_right(soko); break;
        case 32:
            soko->map = map_in_array(soko);
            soko->x = soko->save_x;
            soko->y = soko->save_y; break;
    }
}
