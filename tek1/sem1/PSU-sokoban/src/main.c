/*
** EPITECH PROJECT, 2022
** B-PSU-100-PAR-1-2-sokoban-luca.martinet
** File description:
** temp_main.c
*/

#include "../include/my.h"

void descrition_plus_use(void)
{
    my_printf("USAGE\n");
    my_printf("\t./my_sokoban {file map name}\n");
    my_printf("DESCRIPTION\n");
    my_printf("\tmap file representing the warehouse map, containing ");
    my_printf("\'#\' for walls,\n");
    my_printf("\t'P\' for the player, \'X\' for boxes and \'O\' for ");
    my_printf("\tstorage locations.\n");
}

int my_sokoban(soko_t *soko)
{
    initscr();
    noecho();
    curs_set(0);
    clear();
    sokoban_loop(soko);
    return 0;
}

void print_array(soko_t *soko, char **map)
{
    for (int i = 0; i < soko->lines; i++) {
        for (int j = 0; j < soko->columns; j++) {
            my_printf("%c", map[i][j]);
        }
        my_putchar('\n');
    }
}

int main(int ac, char **av)
{
    soko_t soko = {0};
    if (ac != 2)
        return 84;
    if (av[1][0] == '-' && av[1][1] == 'h') {
        descrition_plus_use();
        return 0;
    }
    soko.buf = open_file(av[1]);
    if (soko.buf == NULL)
        return 84;
    map_to_doulbe_char(&soko);
    check_map(&(soko));
    my_sokoban(&(soko));
    return 0;
}
