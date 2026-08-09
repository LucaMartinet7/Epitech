/*
** EPITECH PROJECT, 2024
** B-NWP-400-BAR-4-1-myteams-jules.dufraiche
** File description:
** commands
*/

#include "client.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

command_t commands[] = {
    {"login", handle_login},
    {"logout", handle_logout},
    {"help", handle_help}
};

void handle_logout(char *message, client_t *client)
{
    if (!client->connected) {
        printf("You are not logged in.\n");
        return;
    }
    client->connected = false;
    free(client->name);
    client->name = NULL;
    client_event_logged_out(client->uuid, client->name);
    printf("You have been logged out.\n");
}

void handle_help(char *message, client_t *client)
{
    printf("Available commands:\n");
    printf("/login \"username\" - Log in to the server\n");
    printf("/logout [\"username\"] - Log out of the server\n");
}

void handle_login(char *message, client_t *client)
{
    char **args = NULL;
    int len = 0;

    args = str_to_wrd_array(message, &len);
    if (len != 2) {
        printf("USAGE: /login [\"username\"]\n");
        free_array(args, len);
        return;
    }
    client->name = strdup(args[1]);
    client->connected = true;
    server_event_user_logged_in(client->name);
    free_array(args, len);
}

void process_input(client_t *client)
{
    int len = 0;
    char **cmd = str_to_wrd_array(client->line, &len);

    if ((!client->connected && strcmp(cmd[0], "/login")) ||
        (strcmp(cmd[0], "/login") == 0 && client->connected)) {
        client->connected ? client_error_already_exist() : client_error_unauthorized();
        free_array(cmd, len);
        return;
    }

    for (size_t i = 0; i < sizeof(commands) / sizeof(command_t); i++) {
        if (strcmp(cmd[0] + 1, commands[i].name) != 0) continue;
        commands[i].handler(client->line, client);
        break;
    }
    free_array(cmd, len);
}
