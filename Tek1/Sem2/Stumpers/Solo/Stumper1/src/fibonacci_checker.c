/*
** EPITECH PROJECT, 2023
** fibo
** File description:
** fibo
*/

#include "../include/my.h"
#include <stdio.h>
#include <stdlib.h>

int check_condition(int comp, int num3)
{
    if (comp == num3)
        return 1;
    return 0;
}

int check_value(int value)
{
    if (value == 1)
        write(1, "OK\n", 3);
    else
        write(1, "Not a Fibonacci sequence\n", 25);
    return 0;
}

int main(int ac, char **av)
{
    if (ac == 1)
        return 84;
    int num1 = 0;
    int num2 = 0;
    int num3 = 0;
    int comp = 0;
    int value = 0;

    for (int i = 1; i < ac - 2; i++) {
        num1 = atoi(av[i]);
        num2 = atoi(av[i + 1]);
        num3 = atoi(av[i + 2]);
        comp = num1 + num2;
        if (check_condition(comp, num3))
            value = 1;
        else
            value = 2;
    }
    check_value(value);
    return 0;
}
