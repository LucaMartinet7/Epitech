/*
** EPITECH PROJECT, 2023
** temp
** File description:
** utils2
*/

#include "../include/pal.h"

bool is_palindrome_2(int nbr)
{
    int nb = nbr;
    int rev = 0;
    int rem = 0;

    while (nb != 0) {
        rem = nb % 10;
        rev = rev * 10 + rem;
        nb /= 10;
    }
    if (nbr == rev)
        return true;
    return false;
}

int revert_p(int num)
{
    int res = 0;
    while (num > 0) {
        res = (res * 10) + (num % 10);
        num = num / 10;
    }
    return res;
}
