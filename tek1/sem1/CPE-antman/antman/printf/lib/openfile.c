/*
** EPITECH PROJECT, 2022
** B-CPE-110-PAR-1-2-antman-luca.martinet
** File description:
** openfile.c
*/

#include "../include/my_printf.h"

char *openfile(char *av)
{
    int fd = open(av, O_RDONLY);
    if (fd == -1)
        return NULL;
    struct stat ap;
    if (stat(av, &ap) == -1)
        return NULL;
    int buffsize = ap.st_size;
    char *buffer = malloc(sizeof(char) * (buffsize + 1));
    if (read(fd, buffer, buffsize) <= 0)
        return NULL;
    close(fd);
    buffer[ap.st_size] = '\0';
    return buffer;
}
