/*
** EPITECH PROJECT, 2024
** B-NWP-400-BAR-4-1-myftp-luca.martinet [WSL: Ubuntu]
** File description:
** loop
*/

#include "myftp.h"

void loop(server_t *server)
{
    while (1) {
        FD_ZERO(&server->readfds);
        FD_SET(server->fd_server, &server->readfds);
        server->max_sd = server->fd_server;
        for (int i = 0; i < MAX_USERS; i++)
            set_fd(server, i);
        server->activity = select(server->max_sd + 1, &server->readfds,
            NULL, NULL, 0);
        if ((server->activity < 0) && (errno != EINTR))
            printf("select error");
        if (FD_ISSET(server->fd_server, &server->readfds))
            accept_new_client(server);
        check_cmds(server);
    }
}
