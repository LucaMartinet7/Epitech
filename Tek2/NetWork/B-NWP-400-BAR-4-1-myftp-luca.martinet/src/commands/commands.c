/*
** EPITECH PROJECT, 2024
** B-NWP-400-BAR-4-1-myftp-luca.martinet
** File description:
** commands
*/

#include "myftp.h"
#include <string.h>

static void more_opt(server_t *server, char *command, char *compare[5])
{
    if (strcmp(command, compare[5]) == 0)
        dprintf(server->sd, "200 No operation performed.\r\n");
    else if (strcmp(command, compare[6]) == 0)
        pwd_cmd(server);
    else
        dprintf(server->sd, "530 Unknown command.\r\n");
}

static void no_opt(server_t *server, int i, char *command, char *compare[5])
{
    if (strcmp(command, compare[4]) == 0)
        quit_cmd(server, i);
    else if (strcmp(command, compare[1]) == 0)
        pass_cmd(server);
    else
        more_opt(server, command, compare);
}

static void check_cmd2(server_t *server, int i,
    char *command, char *compare[5])
{
    if (strcmp(command, compare[2]) == 0)
        passive_cmd(server, &server->data_socket_fd, &server->addr);
    else if (strcmp(command, compare[3]) == 0)
        help_cmd(server);
    else
        no_opt(server, i, command, compare);
}

void check_cmd(server_t *server, int i)
{
    char command[10];
    char *compare[7] = {"USER", "PASS", "PASV", "HELP", "QUIT", "NOOP", "PWD"};

    if (server->valread > 0) {
        server->buffer[server->valread] = '\0';
        sscanf(server->buffer, "%s", command);
        if (strcmp(command, compare[0]) == 0)
            user_cmd(server);
        else
            check_cmd2(server, i, command, compare);
    }
}
