/*
** EPITECH PROJECT, 2024
** B-NWP-400-BAR-4-1-myteams-jules.dufraiche
** File description:
** get_input
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#include "client.h"
#include "shared.h"

void check_logout(client_t *client, char *cmd)
{
    if (!strcmp(cmd, "/logout")) {
        if (client->connected != false)
            client_event_logged_out(client->uuid, client->name);
        close(client->sockFd);
        exit(0);
    }
}

void free_array(char **array, int len)
{
    for (int i = 0; i < len; i++)
        free(array[i]);
    free(array);
}

void read_server(client_t *client)
{
    char buffer[BUFFERSIZE] = {0};

    if (read(client->sockFd, buffer, BUFFERSIZE) == 0) {
        close(client->sockFd);
        exit(0);
    }
    printf("%s\n", buffer);
}
