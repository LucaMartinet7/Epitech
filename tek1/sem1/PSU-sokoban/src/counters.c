/*
** EPITECH PROJECT, 2022
** B-PSU-100-PAR-1-2-sokoban-luca.martinet
** File description:
** counters.c
*/

#include "../include/my.h"

void count_lines(soko_t *soko)
{
    int lines = 0;
    for (int i = 0; soko->buf[i] != '\0'; i++) {
        if (soko->buf[i] == '\n')
            lines++;
    }
    soko->lines = lines + 1;
}

void count_columns(soko_t *soko)
{
    int columns = 0;
    for (int i = 0; soko->buf[i] != '\n'; i++) {
        columns++;
    }
    soko->columns = columns;
}
