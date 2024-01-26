/*
** EPITECH PROJECT, 2022
** my_put_binary.c
** File description:
** decimal to binary converter
*/

#include "my.h"

unsigned int my_put_binary(unsigned int decimalnum)
{
    int i = 0;
    int binarynum[100];

    while (decimalnum > 0) {
        binarynum[i] = decimalnum % 2;
        decimalnum = decimalnum / 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--) {
        my_put_unsigned_nbr(binarynum[j]);
    }
    return 0;
}
