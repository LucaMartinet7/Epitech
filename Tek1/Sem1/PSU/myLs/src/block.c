/*
** EPITECH PROJECT, 2022
** B-PSU-100-PAR-1-2-myls-luca.martinet
** File description:
** block.c
*/

#include "../include/my.h"

int block_total(struct dirent *file, struct stat info, char **av)
{
    DIR *dir = opendir(av);
    int i = 0;

    while ((file = readdir(dir)) != NULL) {
        stat(file->d_name, &info);
        if (file->d_name[0] != ".") {
            i = i + info.st_blocks;
        }
    }
    i = i / 2;
    if (closedir(dir) == -1)
        exit(-1);
    return i;
}
