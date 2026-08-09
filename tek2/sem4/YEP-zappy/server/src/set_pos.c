/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** map server Zappy
*/

#include "server.h"
#include "resources.h"

void set_player_pos_in_game(server_t *server)
{
    return;
}

void set_player_pos_begin(server_t *server)
{
    int x_pos = 0;
    int y_pos = 0;

    for (int i = server->old_nb; i < server->nb_players; i++) {
        do {
            x_pos = rand() % server->width;
            y_pos = rand() % server->height;
        } while (server->map[y_pos][x_pos][0] != 'V');
        server->map[y_pos][x_pos][0] = 'P';
        server->map[y_pos][x_pos][1] = (i + 1) + '0';
        server->map[y_pos][x_pos][2] = '\0';
    }
    server->old_nb = server->nb_players;
}

void set_map_ressources_pos(server_t *server, resources_t *resources)
{
    int x_pos = 0;
    int y_pos = 0;
    double action_time = 7.0 / server->freq;
}
