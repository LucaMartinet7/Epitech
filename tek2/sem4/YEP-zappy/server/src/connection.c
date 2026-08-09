/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Connections Zappy
*/

#include "player.h"

void process_client_sockets(server_t *server, player_t **player)
{
    int sd;

    for (int i = 0; i < server->team_size; i++) {
        sd = server->client_sockets[i];
        if (FD_ISSET(sd, &server->readfds))
            handle_client_message(sd, server, player);
    }
}

void set_fd(server_t *server, int *max_sd, int *sd)
{
    FD_ZERO(&server->readfds);
    FD_SET(server->fd, &server->readfds);
    *max_sd = server->fd;
    for (int i = 0; i < server->team_size; i++) {
        *sd = server->client_sockets[i];
        if (*sd > 0) {
            FD_SET(*sd, &server->readfds);
        }
        if (*sd > *max_sd) {
            *max_sd = *sd;
        }
    }
}

void handle_connect(int socket, server_t *server, player_t **player)
{
    char *str = malloc(sizeof(char) * 4);

    str[0] = server->nb_players + '0';
    str[1] = '\n';
    str[2] = '\0';
    send(socket, str, strlen(str), 0);
    free(str);
}

void handle_fork(int socket, server_t *server, player_t **player)
{
    server->team_size++;
    send(socket, "ok\n", strlen("ok\n"), 0);
}

void handle_client_message(int client_socket, server_t *server,
    player_t **player)
{
    char buffer[BUFFER_SIZE];
    char *command;
    int valread = read(client_socket, buffer, BUFFER_SIZE);

    if (valread == 0) {
        getpeername(client_socket, (struct sockaddr *)
        &server->address, (socklen_t *)&server->addrlen);
        delete_user(server);
        server->nb_players--;
        close(client_socket);
        client_socket = 0;
        free(player[server->nb_players]);
    } else {
        buffer[valread] = '\0';
        command = strtok(buffer, " ");
        if (command != NULL) {
            dispatch_command(command, client_socket, server, player);
        }
    }
}
