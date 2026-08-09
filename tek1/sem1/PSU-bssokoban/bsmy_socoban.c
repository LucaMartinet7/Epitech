/*
** EPITECH PROJECT, 2022
** B-PSU-100-PAR-1-2-bssokoban-luca.martinet
** File description:
** ftgtoi.c
*/

#include <ncurses.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
    WINDOW *box;
    char *txt= "Hello World !";
    int size= strlen(txt);

    initscr();
    while(1) {
        clear();
        mvprintw(LINES/2, (COLS / 2) - (size / 2), txt);
        refresh();
        if(getch() != 410)
            break;
    }
    endwin();
    free(box);
    return 0;
}