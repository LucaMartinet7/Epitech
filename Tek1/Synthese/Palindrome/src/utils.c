/*
** EPITECH PROJECT, 2023
** temp
** File description:
** util
*/

#include <string.h>
#include <ctype.h>
#include "../include/pal.h"

int v_nb(pal_t *pal, char *str)
{
    if (str == NULL)
        return 84;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isdigit(str[i]) == 0) {
            pal->status = 84;
            return 84;
        }
    }
    pal->status = 0;
    return 0;
}

bool is_palindrome(pal_t *pal)
{
    int nb = pal->nb;
    int rev = 0;
    int rem = 0;

    while (nb != 0) {
        rem = nb % 10;
        rev = rev * 10 + rem;
        nb /= 10;
    }
    if (pal->nb == rev)
        return true;
    return false;
}

int convert_base(int nbr, int base)
{
    long int nb;
    long int res;
    if (nbr == 0)
        return 0;
    nb = nbr % base;
    res = convert_base(nbr / base, base);

    return res * 10 + nb;
}

int do_addition(pal_t *pal)
{
    int nb = pal->nb;
    int rev = 0;
    int rem = 0;

    while (nb != 0) {
        rem = nb % 10;
        rev = rev * 10 + rem;
        nb /= 10;
    }
    
    return rev;
}

int revert_base(int nbr, int base)
{
    int res = 0;
    int power = 1;
    if (nbr == 0 || (base < 2 || base > 10)) {
        return 0;
    }
    while (nbr > 0) {
        int digit = nbr % 10;
        if (digit >= base) {
            return 0;
        }
        res = res + digit * power;
        power = power * base;
        nbr = nbr / 10;
    }
    return res;
}
