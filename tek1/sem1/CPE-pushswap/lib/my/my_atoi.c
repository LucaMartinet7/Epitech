/*
** EPITECH PROJECT, 2022
** B-CPE-110-PAR-1-2-pushswap-luca.martinet
** File description:
** my_atoi.c
*/

#include "../../include/my.h"

int my_atoi(char *str)
{
    int i = 0;
    int nb = 0;

    while (str && str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9')
            return (-1);
        nb = (nb * 10) + (str[i] - '0');
        i++;
    }
    return (nb);
}
