/*
** EPITECH PROJECT, 2024
** B-NWP-400-BAR-4-1-myftp-luca.martinet
** File description:
** main
*/

#include "myftp.h"

static bool checknbr(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9')
            return false;
    }
    if (atoi(str) < 1024 || atoi(str) > 65535) {
        fprintf(stderr, "port is not valid\n");
        return false;
    }
    return true;
}

static int check_args(int ac, char **av)
{
    char path[1000 + 1];

    if (ac != 3) {
        fprintf(stderr, "Usage: ./myftp port path\n");
        return 84;
    }
    if (!checknbr(av[1])) {
        fprintf(stderr, "port is not valid\n");
        return 84;
    }
    realpath(av[2], path);
    if (chdir(path) != 0) {
        fprintf(stderr, "path is not valid\n");
        return 84;
    }
    return 0;
}

server_t *init_struct(char **av)
{
    server_t *server = malloc(sizeof(server_t));

    server->port = atoi(av[1]);
    server->fd_server = 0;
    server->new_socket = 0;
    server->data_socket_fd = 0;
    server->opt = 1;
    server->addrlen = sizeof(server->addr);
    server->buffer[BUFFER_SIZE] = '\0';
    server->path = av[2];
    server->user = false;
    server->pass = false;
    return server;
}

int main(int ac, char **av)
{
    server_t *server;

    if (check_args(ac, av) == 84)
        return 84;
    server = init_struct(av);
    start_server(server);
    loop(server);
    return 0;
}
