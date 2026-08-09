/*
** EPITECH PROJECT, 2023
** B-SYN-200-PAR-2-1-projtester-luca.martinet
** File description:
** parse
*/

#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/test.h"

int check_dir(test_t *ts, char *str)
{
    DIR *dir = opendir(str);
    struct dirent *file;

    if (dir == NULL)
        return 84;
    if ((file = readdir(dir)) == NULL)
        return 84;
    else if (file->d_type == DT_DIR || file->d_type == DT_REG)
        search_trd(ts, str);
    closedir(dir);
    return 0;
}

int parse2(test_t *ts, int ac, char **av)
{
    if (ac == 2 && check_dir(ts, av[1]) != 84)
        return 0;
    else
        return 84;
    return 0;
}

int parse(test_t *ts, int ac, char **av)
{
    for (int i = 1; i < ac; i++) {
        if (parse2(ts, ac, av) == 84)
            return 84;
        else
            return 0;
    }
    return 0;
}
