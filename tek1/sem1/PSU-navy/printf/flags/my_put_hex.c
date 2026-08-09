/*
** EPITECH PROJECT, 2022
** int to hex
** File description:
** int to hex
*/

#include <stdlib.h>
#include "../include/my_printf.h"

int power(int nb)
{
    int i = 0;
    int comp1 = my_compute_power_rec(16, i);
    int comp2 = my_compute_power_rec(16, i + 1);
    if (nb > 1 && nb < 16) {
        return 2;
    } while (nb > comp1 && nb < comp2) {
        i++;
    }
    return i;
}

char *hex_maj(int nb)
{
    int nb2 = nb;
    int temp;
    int i = 0;
    int size = power(nb);
    char *res = malloc(sizeof(char) * size + 1);
    while (nb2 != 0) {
        temp = nb2 % 16;
        if (temp < 10) {
            temp = temp + 48;
        } else {
            temp = temp + 55;
        }
        res[i] = temp;
        nb2 = nb2 / 16;
        i++;
    }
    reverse_string(res);
    res[i] = '\0';
    return res;
}

char *hex_min(int nb)
{
    int i = 0;
    int nb2 = nb;
    int temp;
    int size = power(nb);
    char *res = malloc(sizeof(char) * size + 1);
    while (nb2 != 0) {
        temp = nb2 % 16;
        if (temp < 10) {
            temp = temp + 48;
        } else {
            temp = temp + 87;
        }
        res[i] = temp;
        nb2 = nb2 / 16;
        i++;
    }
    reverse_string(res);
    res[i] = '\0';
    return res;
}
