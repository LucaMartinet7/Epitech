/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** map server Zappy
*/

#include "server.h"
#include "resources.h"

void user_found(server_t *server, int i, int j)
{
    if (server->map[i][j][0] == 'P' &&
        server->map[i][j][1] == server->nb_players + '0') {
        server->map[i][j][0] = 'V';
        server->map[i][j][1] = '\0';
        create_file(server);
    }
}

void delete_user(server_t *server)
{
    for (int i = 0; i < server->height; i++) {
        for (int j = 0; j < server->width; j++) {
            user_found(server, i, j);
        }
    }
}

void set_default_map(server_t *server)
{
    server->map = malloc(sizeof(char **) * server->height);
    for (int i = 0; i < server->height; i++) {
        server->map[i] = malloc(sizeof(char *) * server->width);
        for (int j = 0; j < server->width; j++) {
            server->map[i][j] = malloc(sizeof(char) * 4);
            server->map[i][j][0] = 'V';
            server->map[i][j][1] = '\0';
        }
    }
}
