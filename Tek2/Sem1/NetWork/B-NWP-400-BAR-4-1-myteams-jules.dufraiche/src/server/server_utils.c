/*
** EPITECH PROJECT, 2024
** B-NWP-400-BAR-4-1-myteams-jules.dufraiche
** File description:
** server_utils
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#include "server.h"

static void create_socket(server_t *server)
{
    server->server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server->server_fd == -1) {
        perror("socket");
        exit(84);
    }
    server->server_addr.sin_family = AF_INET;
    server->server_addr.sin_addr.s_addr = INADDR_ANY;
    server->server_addr.sin_port = htons(server->port);
    bind_and_listen(server);
}

void init_struct(server_t *server)
{
    server->addrlen = sizeof(server->server_addr);
    server->new_socket = 0;
    server->server_fd = 0;
    server->port = 0;
    server->messages = malloc(sizeof(msg_list_t));
    if (server->messages == NULL)
        exit(84);
    server->messages->head = NULL;
    server->messages->n = 0;
}

server_t *create_server(char **av)
{
    server_t server;
    memset(&server, 0, sizeof(server_t));
    for (int i = 0; i < MAX_CLIENTS; i++)
        server.clisock[i] = 0;
    init_struct(&server);
    server.port = atoi(av[1]);
    create_socket(&server);
    return &server;
}

void destroy_server(server_t *server)
{
    if (server->server_fd > 0)
        close(server->server_fd);
    free(server);
}
