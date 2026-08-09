/*
** EPITECH PROJECT, 2023
** clean str
** File description:
** clean str
*/

#include "../my.h"

char *remove_spaces(char *change)
{
    int counter = 0;
    int j = 0;
    while (j < my_strlen(change)) {
        if (change[j] == 46 && j == 0)
            change[j] = change[counter];
        else if (change[j] == 46) {
            counter++;
        }
        change[j] = change[counter];
        j++;
        counter++;
    }
    return change;
}

char *remove_random_letters(char *str)
{
    for (int i = 0; i < my_strlen(str); i++) {
        if ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122)
            || str[i] == 32 || str[i] == 63 || str[i] == 33)
            str[i] = str[i];
        else
            str[i] = '.';
    }
    str = remove_spaces(str);
    return str;
}

int main(int ac, char **av)
{
    if (ac != 2)
        return 84;
    char *str = av[1];
    str = remove_random_letters(str);
    write(1, str, my_strlen(str));
    write(1, "\n", 3);
}
