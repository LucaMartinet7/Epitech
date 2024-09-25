/*
** EPITECH PROJECT, 2024
** B-NWP-400-BAR-4-1-myftp-luca.martinet
** File description:
** ftp_server
*/

#include "myftp.h"

void bind_listen(server_t *server)
{
    check_ifs(bind(server->fd_server, (struct sockaddr *)&server->addr,
        sizeof(server->addr)) < 0, "bind failed");
    check_ifs(listen(server->fd_server, 3) < 0, "listen failed");
}

void set_socket(server_t *server)
{
    server->fd_server = socket(AF_INET, SOCK_STREAM, 0);
    check_ifs(server->fd_server < 0, "socket failed");
    check_ifs(setsockopt(server->fd_server, SOL_SOCKET, SO_REUSEADDR,
    &server->opt, sizeof(server->opt)) < 0, "setsockopt failed");
    server->addr.sin_family = AF_INET;
    server->addr.sin_addr.s_addr = INADDR_ANY;
    server->addr.sin_port = htons(server->port);
}

int start_server(server_t *server)
{
    for (int i = 0; i < MAX_USERS; i++)
        server->client_socket[i] = 0;
    set_socket(server);
    bind_listen(server);
    server->addrlen = sizeof(server->addr);
    printf("Server listening on port %d\n", ntohs(server->addr.sin_port));
    return 0;
}
