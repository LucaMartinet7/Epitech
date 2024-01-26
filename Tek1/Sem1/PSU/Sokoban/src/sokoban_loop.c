/*
** EPITECH PROJECT, 2022
** B-PSU-100-PAR-1-2-sokoban-luca.martinet
** File description:
** sokoban_loop.c
*/

#include "../include/my.h"

void display_map(soko_t *soko)
{
    for (int i = 0; soko->map[i] != NULL; i++) {
        mvprintw(i, 100, "%s\n", soko->map[i]);
    }
}

int sokoban_loop(soko_t *soko)
{
    int key = 0;
    display_map(soko);
    initscr();
    noecho();
    while (key != 32) {
        key = getch();
        cases(soko, key);
        display_map(soko);
        refresh();
    }
    endwin();
    return 0;
}
