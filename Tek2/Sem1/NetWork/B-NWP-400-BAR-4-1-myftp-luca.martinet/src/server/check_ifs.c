/*
** EPITECH PROJECT, 2024
** B-NWP-400-BAR-4-1-myftp-luca.martinet [WSL: Ubuntu]
** File description:
** check_ifs
*/

#include "myftp.h"

void set_fd(server_t *server, int i)
{
    server->sd = server->client_socket[i];
    if (server->sd > 0)
        FD_SET(server->sd, &server->readfds);
    if (server->sd > server->max_sd)
        server->max_sd = server->sd;
}

void check_ifs(int condition, const char *message)
{
    if (condition) {
        perror(message);
        exit(EXIT_FAILURE);
    }
}
