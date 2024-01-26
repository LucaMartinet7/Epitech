/*
** EPITECH PROJECT, 2023
** stumper
** File description:
** stumper
*/

#include "../include/my.h"

int errors(int ac, char **av)
{
    if (ac != 2)
        return 1;
    return 0;
}

int main(int ac, char **av)
{
    my_strlowcase(av[1]);
    int len = my_strlen(av[1]);
    if (errors(ac, av) == 1) {
        return 84;
    }
    if (av[1][0] == av[1][len - 1]) {
        write(1, "palindome!\n", 10);
        write(1, "\n", 1);
        } else {
        write(1, "not pallindrome.\n", 16);
        write(1, "\n", 1);
    }
    return 0;
}
