/*
** EPITECH PROJECT, 2024
** B-NWP-400-BAR-4-1-myteams-jules.dufraiche [WSL: Ubuntu]
** File description:
** process
*/

#include "client.h"
#include "shared.h"

int process_cli(char **av)
{
    client_t *client = init_client(av);

    if (start_client(client) == ERROR) {
        destroy_client(client);
        return ERROR;
    }
    destroy_client(client);
    return SUCCESS;
}
