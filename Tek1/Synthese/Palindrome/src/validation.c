/*
** EPITECH PROJECT, 2023
** temp
** File description:
** validation
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/pal.h"

bool check_args(pal_t *pal)
{
    if (pal->n > 0 && pal->p > 0)
        return false;
    if (pal->n == 0 && pal->p == 0)
        return false;
    if (pal->base > 10 || pal->base < 2)
        return false;
    return true;
}

void get_args_valid_2(pal_t *pal, char **av, int i)
{
    if (strcmp(av[i], "-imax") == 0 && v_nb(pal, av[i + 1]) == 0) {
        pal->imax = atoi(av[i + 1]);
        pal->check = 1;
    } if (strcmp(av[i], "-imin") == 0 && v_nb(pal, av[i + 1]) == 0) {
        pal->imin = atoi(av[i + 1]);
        pal->check = 1;
    } if (strcmp(av[i], "-b") == 0 && v_nb(pal, av[i + 1]) == 0) {
            pal->base = atoi(av[i + 1]);
            pal->check = 1;
    }
}

int get_args_valid(pal_t *pal, int ac, char **av)
{
    int i;
    for (i = 1; i != ac; i++) {
        if (strcmp(av[i], "-n") == 0 && v_nb(pal, av[i + 1]) == 0) {
            pal->n++;
            pal->check = 1;
            pal->nb = atoi(av[i + 1]);
        } if (strcmp(av[i], "-p") == 0 && v_nb(pal, av[i + 1]) == 0) {
            pal->nb_p = atoi(av[i + 1]);
            pal->p++;
            pal->check = 1;
        } else
            get_args_valid_2(pal, av, i);
    } if (pal->check == 0 || !check_args(pal)) {
        printf("invalid argument\n");
        pal->status = 84;
    } else
        pal->status = chose_palindrome(pal);
    return pal->status;
}

int validation(pal_t *pal, int ac, char **av)
{
    if (ac == 3 && !strcmp(av[1], "-n") && v_nb(pal, av[2]) == 0) {
        pal->n++;
        pal->nb = atoi(av[2]);
        palindrome(pal);
    } else
        pal->status = get_args_valid(pal, ac, av);
    return pal->status;
}
