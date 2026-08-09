/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Manage file Zappy
*/

#include "server.h"
#include <fcntl.h>

void write_header_file(int file, server_t *server)
{
    char str[4];

    sprintf(str, "%d", server->height);
    write(file, str, strlen(str));
    write(file, ":", strlen(":"));
    sprintf(str, "%d", server->width);
    write(file, str, strlen(str));
    write(file, "\n", strlen("\n"));
}

void write_end_file(int file)
{
    write(file, "END\n", strlen("END\n"));
}

void check_end(server_t *server, int j, int file)
{
    if (j != server->width - 1) {
        write(file, " ", strlen(" "));
    }
}

void create_file(server_t *server)
{
    const char *path = "map.txt";
    int file = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);

    write_header_file(file, server);
    for (int i = 0; i < server->height; i++) {
        write(file, "{", strlen("{"));
        for (int j = 0; j < server->width; j++) {
            write(file, "\"", strlen("\""));
            write(file, server->map[i][j], strlen(server->map[i][j]));
            write(file, "\"", strlen("\""));
            check_end(server, j, file);
        }
        write(file, "}", strlen("}"));
        write(file, "\n", strlen("\n"));
    }
    write_end_file(file);
    close(file);
}
