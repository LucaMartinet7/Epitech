/*
** EPITECH PROJECT, 2024
** B-YEP-400-BAR-4-1-zappy-noe.kurata [WSL: Ubuntu]
** File description:
** player
*/

#ifndef PLAYER_H_
    #define PLAYER_H_

    #include "server.h"

typedef struct player_s {
    int id;
    int vision;
    int level;
    int life;
    int x_pos;
    int y_pos;
    char *teams_name;
    clock_t start;
} player_t;

int start_server(char **av, server_t *server, player_t **player);
void player_value(int at, player_t **player);
void search_player(server_t *server, player_t **player);
void dispatch_command(const char *command, int socket, server_t *server,
    player_t **player);
void handle_client_message(int client_socket, server_t *server,
    player_t **player);
void process_client_sockets(server_t *server, player_t **player);

#endif /* !PLAYER_H_ */
