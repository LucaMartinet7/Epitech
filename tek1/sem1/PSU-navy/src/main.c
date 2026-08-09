/*
** EPITECH PROJECT, 2022
** B-PSU-100-PAR-1-2-navy-noe.kurata
** File description:
** process_info.c
*/

#include "../include/navy.h"

int helper(char *av)
{
    if (av[0] == '-' && av[1]) {
        my_printf("USAGE\n");
        my_printf("\t./navy [first_player_pid] navy_positions\n");
        my_printf("DECRIPTION\n");
        my_printf("\tfirst_player_pid: only for the 2nd player. pid of the first player.\n");
        my_printf("\tnavy_positions: file representing the positions of the ships.\n");
        return 0;
    }
    return 84;
}

int main(int ac, char **av)
{
    if (helper(av[1]) != 0)
        return 84;
}