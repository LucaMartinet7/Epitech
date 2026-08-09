/*
** EPITECH PROJECT, 2022
** B-BOO-101-PAR-1-1-phoenixd01-noe.kurata
** File description:
** is_prime_number.c
*/

#include "../include/my_printf.h"

int is_prime_number(int nb)
{
    if (nb == 2 || nb == 3)
        return 1;
    if (nb < 2)
        return 0;
    for (int i = 2; i < nb; i++)
        if (nb % i == 0)
            return 0;
    return 1;
}
