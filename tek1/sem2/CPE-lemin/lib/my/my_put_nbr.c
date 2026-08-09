/*
** EPITECH PROJECT, 2022
** my_put_nbr.c
** File description:
** display nbr
*/

#include "my.h"

void exception(void)
{
    my_putchar('-');
    my_putchar('2');
    my_putchar('1');
    my_putchar('4');
    my_putchar('7');
    my_putchar('4');
    my_putchar('8');
    my_putchar('3');
    my_putchar('6');
    my_putchar('4');
    my_putchar('8');
}

int my_put_nbr(int nb)
{
    int j = -2147483648;
    if (nb == j) {
        exception();
        return 0;
    }
    if (nb == 0)
        return 0;
    else if (nb < 0) {
        nb = -nb;
        my_putchar('-');
    }
    my_put_nbr(nb / 10);
    char n = nb % 10 + 48;
    my_putchar(n);
    return 0;
}
