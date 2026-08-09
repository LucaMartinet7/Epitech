/*
** EPITECH PROJECT, 2024
** B-NWP-400-BAR-4-1-myteams-jules.dufraiche
** File description:
** process
*/

#include <stdio.h>

#include "server.h"

int process_server(char **av)
{
    server_t *server = init_server(av);

    if (start_server(server) == ERROR) {
        destroy_server(server);
        return ERROR;
    }
    destroy_server(server);
    return SUCCESS;
}
