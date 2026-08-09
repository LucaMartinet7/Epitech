/*
** EPITECH PROJECT, 2022
** int to hexa upper
** File description:
** int to hexa upper
*/

#include "../include/my_printf.h"

int int_to_x_upper(int nb)
{
    if (nb <= 0) {
        return 0;
    } else {
        int_to_x_upper(nb / 16);
    }
    if (nb % 16 < 10) {
        my_put_nbr(nb % 16);
    } else {
        my_putchar(nb % 16 + 55);
    }
}
