/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** unsign decimal
*/

#include "my.h"

unsigned int my_put_unsigned_nbr(unsigned int nb)
{
    if (nb >= 1) {
        nb = +nb;
    }
    my_put_nbr(nb / 10);
    char n = nb % 10 + 48;
    my_putchar(n);
    return 0;
}
