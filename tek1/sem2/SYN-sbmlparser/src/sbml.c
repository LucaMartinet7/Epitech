/*
** EPITECH PROJECT, 2023
** B-SYN-200-PAR-2-1-sbmlparser-luca.martinet
** File description:
** sbml
*/

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../include/sbml.h"

void free_all(sbml_t *sb)
{
    free(sb->buffer);
    for (int i = 0; sb->tab[i] != NULL; i++)
        free(sb->tab[i]);
    free(sb->tab);
    free(sb);
}

int three_args(char **av)
{
    if (check_file(av[1]) == 84)
        return 84;
    if (strcmp(av[2], "-e") == 0 && check_file(av[1]) != 84)
        return 0;
    if (strcmp(av[2], "-json") == 0 && check_file(av[1]) != 84)
        return 0;
    if (strcmp(av[2], "-i") == 0 && check_file(av[1]) != 84)
        return 0;
    else
        return 84;
    return 0;
}

int two_args(sbml_t *sb, char **av)
{
    if (check_file(av[1]) == 84)
        return 84;
    sb->buffer = open_file(av);
    if (sb->buffer == NULL)
        return 84;
    sb->tab = str_word_arr(sb->buffer);
    for (int i = 0; sb->tab[i] != NULL; i++)
        printf("%s\n", sb->tab[i]);
    find_all_categories(sb);
    free_all(sb);
    return 0;
}

int sbml(sbml_t *sb, int ac, char **av)
{
    if (ac == 2 && strcmp(av[1], "-h") == 0) {
        tiret_h();
        return 0;
    }
    if (ac == 1)
        return 84;
    if (ac == 2)
        two_args(sb, av);
    if (ac == 3)
        three_args(av);
    return 0;
}
