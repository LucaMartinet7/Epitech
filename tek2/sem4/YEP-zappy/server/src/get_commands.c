/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Get commands Zappy
*/

#include "commands.h"

void dispatch_command(const char *command, int socket, server_t *server,
    player_t **player)
{
    for (int i = 0; command_mappings[i].command != NULL; i++) {
        if (strcmp(command_mappings[i].command, command) == 0) {
            command_mappings[i].handler(socket, server, player);
            return;
        }
    }
    send(socket, "Unknown command\n", strlen("Unknown command\n"), 0);
}

void handle_inventory(int socket, server_t *server, player_t **player)
{
    send(socket, "Handle Inventory", strlen("Handle Inventory"), 0);
}

void handle_broadcast(int socket, server_t *server, player_t **player)
{
    send(socket, "Handle Broadcast", strlen("Handle Broadcast"), 0);
}

void handle_eject(int socket, server_t *server, player_t **player)
{
    send(socket, "Handle Eject", strlen("Handle Eject"), 0);
}

void handle_incantation(int socket, server_t *server, player_t **player)
{
    send(socket, "Handle Incantation", strlen("Handle Incantation"), 0);
}
