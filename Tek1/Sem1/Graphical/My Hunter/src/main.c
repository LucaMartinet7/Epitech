/*
** EPITECH PROJECT, 2022
** B-MUL-100-PAR-1-2-myhunter-luca.martinet
** File description:
** main.c
*/

#include "../include/my.h"

int main(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        description();
        return 0;
    } else
        hunter_main();
    return 0;
}
