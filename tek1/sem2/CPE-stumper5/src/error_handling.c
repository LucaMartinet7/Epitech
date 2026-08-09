/*
** EPITECH PROJECT, 2023
** error
** File description:
** error
*/

#include "../include/duo.h"

char *open_file(char const *filepath);

int check_space(char const *file)
{
    int len = strlen(file);
    for (int i = 0; i < len; i++) {
        if (file[i] == 32)
            return EXIT_ERROR;
    }
    return 0;
}

int main (int ac, char **av)
{
    char *test = open_and_random_words(av[1]);
    if (check_space(test) == 84)
        return 84;
    return 0;
}
