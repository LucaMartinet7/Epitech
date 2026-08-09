/*
** EPITECH PROJECT, 2023
** temp
** File description:
** main
*/

#include "include/pal.h"

void init_struct(pal_t *pal)
{
    pal->nb = 0;
    pal->base = 10;
    pal->imin = 0;
    pal->imax = 100;
    pal->counter = 0;
    pal->status = 0;
    pal->solution = 0;
    pal->nb_cpy = 0;
    pal->n = 0;
    pal->p = 0;
    pal->check = 0;
    pal->nb_p = 0;
}

int main(int ac, char **av)
{
    if (ac < 2)
        return 84;
    pal_t pal;
    init_struct(&pal);
    validation(&pal, ac, av);
    return pal.status;

}
