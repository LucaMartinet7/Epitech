/*
** EPITECH PROJECT, 2024
** B-NWP-400-BAR-4-1-myteams-jules.dufraiche [WSL: Ubuntu]
** File description:
** connections
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

#include "server.h"

void set_fd(server_t *server, int i)
{
    int sd = server->user[i];

    if (sd > 0)
        FD_SET(sd, &server->readfds);
    if (sd > server->max_sd)
        server->max_sd = sd;
}

void remove_user(server_t *server, int i)
{
    close(server->user[i]);
    printf("User %d disconnected\n", i);
    server->user[i] = 0;
}

void manage_connection(server_t *server)
{
    int new_socket = accept(server->server_fd, (struct sockaddr *)
    &server->server_addr, (socklen_t *)&server->addrlen);

    if (new_socket < 0) {
        perror("manage_connection, accept");
        exit(ERROR);
    }
    printf("New connection, socket fd is %d, ip is : %s, port : %d\n",
    new_socket, inet_ntoa(server->server_addr.sin_addr),
    ntohs(server->server_addr.sin_port));
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (server->user[i] == 0) {
            server->user[i] = new_socket;
            break;
        }
    }
}
