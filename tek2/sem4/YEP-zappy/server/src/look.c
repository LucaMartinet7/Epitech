/*
** EPITECH PROJECT, 2024
** B-YEP-400-BAR-4-1-zappy-noe.kurata [WSL: Ubuntu]
** File description:
** look
*/

#include "player.h"

void handle_look(int client, server_t *server, player_t **player)
{
    send(client, "Handled Look command", strlen("Handled Look command"), 0);
}
