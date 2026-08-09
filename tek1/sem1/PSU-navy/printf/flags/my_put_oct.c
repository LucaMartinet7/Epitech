/*
** EPITECH PROJECT, 2022
** int to oct
** File description:
** int to oct
*/

#include "../include/my_printf.h"

void int_2_oct(int nb)
{
    int i = 0;
    int r = 0;
    if (nb > 7) {
        i = nb % 8;
        nb = (nb - i) / 8;
        int_2_oct(nb);
        my_putchar(i + 48);
    } else {
        my_putchar(nb % 8 + 48);
    }
}
