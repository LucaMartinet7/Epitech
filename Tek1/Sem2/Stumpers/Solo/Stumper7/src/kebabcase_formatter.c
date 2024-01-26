/*
** EPITECH PROJECT, 2023
** stumper
** File description:
** stumper
*/

#include "../include/my.h"

int remove_spaces(char *change)
{
    int counter = 0;
    int j = 0;
    while (j < my_strlen(change)) {
        if (change[j] == 32) {
            counter++;
        }
        change[j] = change[counter];
        j++;
        counter++;
    }
    write(1, change, my_strlen(change));
    write(1, "\n", 1);
}

int main(int ac, char **av)
{
    if (ac != 2)
        return 84;
    int tmp = 0;
    char *change = my_strlowcase(av[1]);
    for (int i = 0; i < my_strlen(av[1]); i++) {
        tmp = change[i];
        if ((tmp >= 48 && tmp < 57) ||
            (tmp >= 65 && tmp <= 90) ||
            (tmp >= 97 && tmp <= 122))
            change[i] = tmp;
        else if (tmp == 33 || tmp == 63)
            change[i] = ' ';
        else
            change[i] = '-';
    }
    remove_spaces(change);
    return 0;
}
