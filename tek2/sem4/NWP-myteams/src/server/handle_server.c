/*
** EPITECH PROJECT, 2024
** B-NWP-400-BAR-4-1-myteams-jules.dufraiche
** File description:
** handle_server
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "server.h"

static int display_usage(const char *bin, const int status)
{
    printf("USAGE: %s port\n\n", bin);
    printf("\t port is the port number on which the server socket listens.\n");
    return status;
}

int handle_server(int ac, char **av)
{
    if (ac != 2 || !is_number(av[1]) || atoi(av[1]) < 1 || atoi(av[1]) > 65535)
        return display_usage(av[0], ERROR);
    if (strcmp(av[1], "-help") == 0)
        return display_usage(av[0], SUCCESS);
    return process_server(av);
}
