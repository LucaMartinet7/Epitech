/*
** EPITECH PROJECT, 2022
** B-CPE-200-PAR-2-2-dante-noe.kurata
** File description:
** open_file.c
*/

#include "../include/solver.h"

char *open_file(char const *filepath)
{
    struct stat ap;
    int fd = open(filepath, O_RDONLY);
    char *buffer;

    if (fd == -1) {
        return NULL;
    }
    if (stat(filepath, &ap) == -1) {
        return NULL;
    }
    buffer = malloc(sizeof(char) * (ap.st_size + 1));
    if (buffer == NULL)
        return NULL;
    if (read(fd, buffer, ap.st_size) < 1)
        return NULL;
    buffer[ap.st_size] = '\0';
    close(fd);
    return buffer;
}
