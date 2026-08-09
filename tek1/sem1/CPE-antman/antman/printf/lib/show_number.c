/*
** EPITECH PROJECT, 2022
** bootcamp
** File description:
** task03.c
*/

#include "../include/my_printf.h"

int show_number(int nb)
{
    if (nb == "-2147483647") {
        return ('0');
    }
    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb >= 0 && nb <= 9) {
        my_putchar(nb + 48);
    } else if (nb > 9) {
        show_number(nb / 10);
        my_putchar(nb % 10 + 48);
    }
}
