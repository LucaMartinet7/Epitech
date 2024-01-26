/*
** EPITECH PROJECT, 2022
** B-PSU-100-PAR-1-2-myls-luca.martinet
** File description:
** my_ls2.c
*/
#include "../include/my.h"

void flag_case(DIR *dir, char **av, int i, struct dirent *file)
{
    switch (av[i + 1][1]) {
        case 'a': my_printf("%s  ", file->d_name); break;
        case 'l': my_ls_l(av); break;
        }
}

int no_conditions(DIR *dir, char **av, int i, struct dirent *file)
{
    if (file->d_name[0] != '.') {
        my_printf("%s  ", file->d_name);
    }
}

int main(int ac, char **av)
{
    int i = 0;
    DIR *dir = opendir(".");
    struct dirent *file;

    if (dir == NULL)
        exit(1);

    while ((file = readdir(dir)) != NULL) {
        if (ac > 1 && av[i + 1][0] == 45)
            flag_case(dir, av, i, file);
        else
            no_conditions(dir, av, i, file);
        }
        my_putchar('\n');
    if (closedir(dir) == -1)
            exit(-1);
    return 0;
}
