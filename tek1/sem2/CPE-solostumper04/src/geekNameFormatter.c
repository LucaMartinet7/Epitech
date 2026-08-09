/*
** EPITECH PROJECT, 2023
** stumper4
** File description:
** stumper 4
*/

#include "../include/my.h"

void cases(char *str, int i)
{
    if (str[i] == 111 || str[i] == 79)
        str[i] = '0';
    if (str[i] == 105 || str[i] == 73)
        str[i] = '1';
    if (str[i] == 117 || str[i] == 85)
        str[i] = '2';
    if (str[i] == 101 || str[i] == 69)
        str[i] = '3';
    if (str[i] == 97 || str[i] == 65)
        str[i] = '4';
    if (str[i] == 121 || str[i] == 89)
        str[i] = '5';
}

int main(int ac, char **av)
{
    if (ac != 2) {
        write(2, "Usage: geekNameFormatter string\n", 32);
        return 84;
    }
    char *str = av[1];
    for (int i = 0; str[i] != '\0'; i++) {
        cases(str, i);
    }
    my_putstr(str);
    my_putchar('\n');
    return 0;
}
