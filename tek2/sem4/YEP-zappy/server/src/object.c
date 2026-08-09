/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Oject Zappy
*/

#include "player.h"

void handle_pick_up(int socket, server_t *server, player_t **player)
{
    send(socket, "Handle Pick Up", strlen("Handle Pick Up"), 0);
}

void handle_set_obj(int socket, server_t *server, player_t **player)
{
    send(socket, "Handle Set Object", strlen("Handle Set Object"), 0);
}
