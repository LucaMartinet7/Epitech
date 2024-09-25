/*
** EPITECH PROJECT, 2024
** B-NWP-400-BAR-4-1-myteams-jules.dufraiche
** File description:
** run_server
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "server.h"

static void handle_sigint(int sig)
{
    (void)sig;
    open = 0;
    printf("Server closed\n");
}

void handle_user(server_t *server, int i)
{
    int read_result = 0;
    int sd = server->user[i];
    char buffer[BUFFER_SIZE];

    if (FD_ISSET(sd, &server->readfds)) {
        read_result = read(sd, buffer, sizeof(buffer));
        if (read_result == 0)
            remove_user(server, i);
        if (read_result < 0) {
            perror("read");
            remove_user(server, i);
        }
    }
}

bool network_handler(server_t *server)
{
    FD_ZERO(&server->readfds);
    FD_SET(server->server_fd, &server->readfds);
    server->max_sd = server->server_fd;
    for (int i = 0; i < MAX_CLIENTS; i++)
        set_fd(server, i);
    if (select(server->max_sd + 1, &server->readfds, NULL, NULL, NULL) < 0) {
        perror("network_handler");
        return false;
    }
    if (FD_ISSET(server->server_fd, &server->readfds))
        manage_connection(server);
    for (int i = 0; i < MAX_CLIENTS; i++)
        handle_user(server, i);
    return true;
}

static int run_server(server_t *server)
{
    if (listen(server->server_fd, MAX_CLIENTS) < 0) {
        perror("run_server");
        close(server->server_fd);
        return ERROR;
    }
    printf("Server started on port %d\n", server->port);
    signal(SIGPIPE, SIG_IGN);
    signal(SIGINT, handle_sigint);
    while (open) {
        if (!network_handler(server))
            return ERROR;
    }
    return SUCCESS;
}

int start_server(server_t *server)
{
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_addr.s_addr = htonl(INADDR_ANY),
        .sin_port = htons(server->port)
    };

    server->server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server->server_fd < 0 || setsockopt(server->server_fd, SOL_SOCKET,
    SO_REUSEADDR, &(int){1}, sizeof(int)) < 0 || bind(server->server_fd,
    (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("could not start server");
        return ERROR;
    }
    return run_server(server);
}
