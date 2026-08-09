/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Set playerr struct value Zappy
*/

#include "player.h"

bool is_player(int y, int x, char ***map)
{
    if (map[y][x][0] == 'P')
        return (true);
    return (false);
}

void find_it(server_t *server, int i, int id, player_t **player)
{
    for (int j = 0; j < server->width; j++) {
        if (is_player(i, j, server->map)) {
            player[id]->y_pos = i;
            player[id]->x_pos = j;
        }
    }
}

void search_player(server_t *server, player_t **player)
{
    for (int id = server->old_nb - 1; id < server->nb_players; id++) {
        for (int i = 0; i < server->height; i++) {
            find_it(server, i, id, player);
        }
    }
}

void player_value(int at, player_t **player)
{
    player[at] = malloc(sizeof(player_t));
    player[at]->level = at;
    player[at]->vision = 1;
    player[at]->level = 1;
    player[at]->life = 1260;
    player[at]->start = clock();
}
