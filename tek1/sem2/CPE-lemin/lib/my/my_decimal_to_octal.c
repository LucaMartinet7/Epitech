/*
** EPITECH PROJECT, 2022
** my_decimal_to_octal.c
** File description:
** decimal to octal
*/

#include "my.h"

unsigned int my_decimal_to_octal(unsigned int decimalnum)
{
    unsigned int octalnum = 0;
    int  i = 1;
    while (decimalnum != 0) {
        octalnum = octalnum + (decimalnum % 8) * i;
        i = i * 10;
        decimalnum = decimalnum / 8;
    }
    my_put_nbr(octalnum);
    return octalnum;
}
