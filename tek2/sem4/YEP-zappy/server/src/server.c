/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** begin server Zappy
*/

#include "player.h"

void set_socket(char **av, server_t *server)
{
    server->fd = socket(AF_INET, SOCK_STREAM, 0);
    check_ifs(server->fd == -1, "socket failed");
    check_ifs(setsockopt(server->fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT
    , &server->opt, sizeof(server->opt)), "setsockopt");
    server->address.sin_family = AF_INET;
    server->address.sin_addr.s_addr = INADDR_ANY;
    server->address.sin_port = htons(atoi(av[2]));
}

void bind_listen(server_t *server)
{
    check_ifs(bind(server->fd, (struct sockaddr *)
    &server->address, sizeof(server->address)) < 0, "bind failed");
    check_ifs(listen(server->fd, 10) < 0, "listen");
}

void accept_new_client(server_t *server, player_t **player)
{
    int new_socket = accept(server->fd, (struct sockaddr *)
        &server->address, (socklen_t *)&server->addrlen);

    if (new_socket < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }
    server->nb_players++;
    set_player_pos_begin(server);
    player_value(server->nb_players - 1, player);
    create_file(server);
    for (int i = 0; i < server->team_size; i++) {
        if (server->client_sockets[i] == 0) {
            server->client_sockets[i] = new_socket;
            break;
        }
    }
}

void close_server(server_t *server)
{
    for (int i = 0; i < server->team_size; i++) {
        if (server->client_sockets[i] != 0) {
            close(server->client_sockets[i]);
        }
    }
    close(server->fd);
}

int start_server(char **av, server_t *server, player_t **player)
{
    int max_sd;
    int sd;

    set_socket(av, server);
    bind_listen(server);
    for (int i = 0; i < server->team_size; i++)
        server->client_sockets[i] = 0;
    create_file(server);
    while (1) {
        set_fd(server, &max_sd, &sd);
        select(max_sd + 1, &server->readfds, NULL, NULL, NULL);
        if (FD_ISSET(server->fd, &server->readfds))
            accept_new_client(server, player);
        process_client_sockets(server, player);
    }
    close_server(server);
    return (0);
}
