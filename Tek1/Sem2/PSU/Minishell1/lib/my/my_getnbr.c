/*
** EPITECH PROJECT, 2022
** get nbr
** File description:
** get nbr
*/

#include "../../include/my.h"

int my_getnbr(char *str)
{
    int nb = 0;
    int neg = 1;
    int i = 0;

    while (str[i] == '+' || str[i] == '-') {
        if (str[i] == '-')
            neg = neg * -1;
        i = i + 1;
    }
    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            nb = nb * 10;
            nb = nb + str[i] - '0';
            i = i + 1;
        } else
            return (nb * neg);
    }
    return (nb * neg);
}
