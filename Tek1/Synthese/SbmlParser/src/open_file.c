/*
** EPITECH PROJECT, 2023
** B-SYN-200-PAR-2-1-sbmlparser-luca.martinet
** File description:
** open_file
*/

#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/sbml.h"

char *open_file(char **av)
{
    int fd = open(av[1], O_RDONLY);
    struct stat st;
    char *str = NULL;

    if (fd == -1) {
        printf("Error: file not found\n");
        return NULL;
    }
    stat(av[1], &st);
    str = malloc(sizeof(char) * (st.st_size + 1));
    read(fd, str, st.st_size);
    str[st.st_size] = '\0';
    close(fd);
    if (str == NULL) {
        printf("Error: file is empty\n");
        return NULL;
    }
    return str;
}
