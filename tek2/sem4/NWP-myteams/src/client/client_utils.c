/*
** EPITECH PROJECT, 2024
** B-NWP-400-BAR-4-1-myteams-jules.dufraiche [WSL: Ubuntu]
** File description:
** client_utils
*/

#include <stdlib.h>
#include <unistd.h>

#include "client.h"
#include "shared.h"

client_t *init_client(char **av)
{
    client_t *client = malloc(sizeof(client_t));

    client->sockFd = -1;
    client->port = atoi(av[2]);
    client->ip = av[1];
    client->connected = false;
    client->name = NULL;
    client->uuid = NULL;
    client->command = NULL;
    return client;
}

void destroy_client(client_t *client)
{
    if (client->sockFd > 0)
        close(client->sockFd);
    free(client);
}
