/*
** EPITECH PROJECT, 2022
** unasigned decimal
** File description:
** unasigned decimal
*/

#include "../include/my_printf.h"

int uns_dec(unsigned int nb)
{
    unsigned int n;
    if (nb > 9) {
        show_number(nb / 10);
    }
    n = nb % 10 + 48;
    my_putchar(n);
    return 0;
}
