/*
** EPITECH PROJECT, 2022
** B-BOO-101-PAR-1-1-phoenixd01-noe.kurata
** File description:
** task06.c
*/

#include "../include/my_printf.h"

int to_number(char const *str)
{
    int res = 0;
    int sign = 1;
    int i = 0;
    while (str[i] == '+' || str[i] == '-') {
        if (str[i] == '-')
            sign = sign * -1;
        i++;
    }
    while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9') {
            write(1, "Invalid character in string\n", 29);
            return 0;
            }
        res = res * 10 + (str[i] - 48);
        i++;
        }
    return res * sign;
}
