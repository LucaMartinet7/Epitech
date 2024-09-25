/*
** EPITECH PROJECT, 2024
** B-NWP-400-BAR-4-1-myftp-luca.martinet [WSL: Ubuntu]
** File description:
** connections
*/

#include "myftp.h"

void accept_new_client(server_t *server)
{
    int new_socket;

    new_socket = accept(server->fd_server,
        (struct sockaddr *)&server->addr, (socklen_t *)&server->addrlen);
    check_ifs(new_socket < 0, "accept failed");
    printf("New connection, socket fd is %d, ip is : %s, port : %d\n",
        new_socket, inet_ntoa(server->addr.sin_addr),
        ntohs(server->addr.sin_port));
    dprintf(new_socket, "220 Service ready for new user please login.\r\n");
    for (int i = 0; i < MAX_USERS; i++) {
        if (server->client_socket[i] == 0) {
            server->client_socket[i] = new_socket;
            break;
        }
    }
}

void check_cmds(server_t *server)
{
    for (int i = 0; i < MAX_USERS; i++) {
        server->sd = server->client_socket[i];
        if (FD_ISSET(server->sd, &server->readfds)) {
            server->valread = read(server->sd, server->buffer,
                BUFFER_SIZE - 1);
            check_cmd(server, i);
        }
    }
}
