/*
** EPITECH PROJECT, 2024
** B-NWP-400-BAR-4-1-myteams-jules.dufraiche [WSL: Ubuntu]
** File description:
** run_client
*/

#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/select.h>

#include "client.h"
#include "shared.h"

void handle_sigint(int sig)
{
    (void)sig;
    open = 0;
    printf("Client closed\n");
}

void handle_stdin(client_t *client)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    read = getline(&line, &len, stdin);
    if (read == -1)
        return;
    line = strtok(line, "\n");
    strncpy(client->line, line, sizeof(client->line) - 1);
    client->line[sizeof(client->line) - 1] = '\0';
    free(line);
    if (strlen(client->line) == 0)
        return;
    process_input(client);
}

void handle_fds(client_t *client, fd_set *fds)
{
    if (FD_ISSET(STDIN_FILENO, fds))
        handle_stdin(client);
    else if (FD_ISSET(client->sockFd, fds))
        read_server(client);
}

static int run_client(client_t *client)
{
    fd_set fds;

    signal(SIGINT, handle_sigint);
    while (open) {
        FD_ZERO(&fds);
        FD_SET(STDIN_FILENO, &fds);
        FD_SET(client->sockFd, &fds);
        if (select(client->sockFd + 1, &fds, NULL, NULL, NULL) == -1) {
            perror("select()");
            exit(ERROR);
        }
        handle_fds(client, &fds);
    }
    return SUCCESS;
}

int start_client(client_t *client)
{
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_addr.s_addr = inet_addr(client->ip),
        .sin_port = htons(client->port)
    };

    client->sockFd = socket(AF_INET, SOCK_STREAM, 0);
    if (client->sockFd == -1 || connect(client->sockFd,
    (struct sockaddr *) &server_addr, sizeof(server_addr)) != 0) {
        perror("start_client");
        return ERROR;
    }
    return run_client(client);
}
