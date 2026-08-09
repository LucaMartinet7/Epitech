/*
** EPITECH PROJECT, 2022
** cat
** File description:
** day12
*/

#include <fcntl.h>
#include <unistd.h>
#include "../include/my.h"

int my_cat(int argc, char *argv[])
{
    int fd;
    int buffer[32000];
    for (int i = 0; i < argc; i++) {
        fd = open(argv[i], O_RDONLY);
    }
    if (fd == -1) {
        return 0;
    }
    int bytes_read;
    while ((bytes_read = read(fd, buffer, 32000))) {
        write(1, buffer, bytes_read);
    }
    close(fd);
}
