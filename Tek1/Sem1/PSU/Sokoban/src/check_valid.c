/*
** EPITECH PROJECT, 2022
** B-PSU-100-PAR-1-2-sokoban-luca.martinet
** File description:
** check_valid.c
*/

#include "../include/my.h"

int check_nb_players(soko_t *soko)
{
    int nb;

    for (int i = 0; soko->buf[i] != '\0'; i++){
        if (soko->buf[i] = 'P')
            nb++;
    }
    if (nb != 1)
        return 84;
    else
        return 0;
}

int check_map(soko_t *soko)
{
    for (int i = 0; soko->buf[i]; i++) {
        if (soko->buf[i] != ' ' || soko->buf[i] != '#'
        || soko->buf[i] != '\n' || soko->buf[i] != 'X'
        || soko->buf[i] != 'P' || soko->buf[i] != 'O')
            return 84;
    }
    if (check_nb_players(soko) == 84) {
        return 84;
    }
    return 0;
}
