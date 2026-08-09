/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Movement Zappy
*/

#include "player.h"

void handle_forward(int client, server_t *server, player_t **player)
{
    int id = player[server->nb_players - 1]->id;

    search_player(server, player);
    server->map[player[id]->y_pos][player[id]->x_pos][0] = 'V';
    server->map[player[id]->y_pos][player[id]->x_pos][1] = '\0';
    if (player[id]->y_pos - 1 < 0) {
        player[id]->y_pos = server->height - 1;
    } else {
        player[id]->y_pos -= 1;
    }
    server->map[player[id]->y_pos][player[id]->x_pos][0] = 'P';
    server->map[player[id]->y_pos][player[id]->x_pos][1] =
    server->nb_players + '0';
    server->map[player[id]->y_pos][player[id]->x_pos][2] = '\0';
    send(client, "ok\n", strlen("ok\n"), 0);
    create_file(server);
}

void handle_right(int client, server_t *server, player_t **player)
{
    int id = player[server->nb_players - 1]->id;

    search_player(server, player);
    server->map[player[id]->y_pos][player[id]->x_pos][0] = 'V';
    server->map[player[id]->y_pos][player[id]->x_pos][1] = '\0';
    if (player[id]->x_pos + 1 >= server->width) {
        player[id]->x_pos = 0;
    } else {
        player[id]->x_pos += 1;
    }
    server->map[player[id]->y_pos][player[id]->x_pos][0] = 'P';
    server->map[player[id]->y_pos][player[id]->x_pos][1] =
    server->nb_players + '0';
    server->map[player[id]->y_pos][player[id]->x_pos][2] = '\0';
    send(client, "ok\n", strlen("ok\n"), 0);
    create_file(server);
}

void handle_left(int client, server_t *server, player_t **player)
{
    int id = player[server->nb_players - 1]->id;

    search_player(server, player);
    server->map[player[id]->y_pos][player[id]->x_pos][0] = 'V';
    server->map[player[id]->y_pos][player[id]->x_pos][1] = '\0';
    if (player[id]->x_pos - 1 < 0) {
        player[id]->x_pos = server->width - 1;
    } else {
        player[id]->x_pos -= 1;
    }
    server->map[player[id]->y_pos][player[id]->x_pos][0] = 'P';
    server->map[player[id]->y_pos][player[id]->x_pos][1] =
    server->nb_players + '0';
    server->map[player[id]->y_pos][player[id]->x_pos][2] = '\0';
    send(client, "ok\n", strlen("ok\n"), 0);
    create_file(server);
}
