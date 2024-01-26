/*
** EPITECH PROJECT, 2023
** B-PSU-100-PAR-1-2-navy-loup.marquez
** File description:
** my_getbr
*/

#include "my.h"

int my_getnbr(char const *str)
{
    int nb = 0, isneg = 1, i = 0,
    max_nb = 2147483647, min_nb = -2147483648;
    for (; str[i] == '+' || str[i] == '-'; i++) {
        if (str[i] == '-') {
            isneg *= -1;
        }
    }
    for (; str[i] != '\0' && str[i] >= 48 && str[i] <= 57; i++) {
        nb = (nb *10) + (str[i] - 48);
    }
    if (((nb * isneg) > max_nb) || ((nb * isneg) < min_nb)) {
        return (0);
    } else {
        return (nb * isneg);
    }
}
