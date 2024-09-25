/*
** EPITECH PROJECT, 2024
** B-NWP-400-BAR-4-1-myftp-luca.martinet
** File description:
** command_type
*/

#include "myftp.h"

void pwd_cmd(server_t *server)
{
    if (server->user && server->pass)
        dprintf(server->sd, "257 %s\r\n", server->path);
    else
        return;
}

void quit_cmd(server_t *server, int i)
{
    getpeername(server->sd, (struct sockaddr *)&server->addr,
                (socklen_t *)&server->addrlen);
    printf("User disconnected, ip %s, port %d\n",
                inet_ntoa(server->addr.sin_addr),
                ntohs(server->addr.sin_port));
    server->user = false;
    server->pass = false;
    dprintf(server->sd, "221 Goodbye.\r\n");
    close(server->sd);
    server->client_socket[i] = 0;
}

bool user_cmd(server_t *server)
{
    char username[MAX_USERS];

    sscanf(server->buffer, "%*s %s", username);
    if (strcmp(username, "Anonymous") == 0) {
        dprintf(server->sd, "331 User name okay, need password.\r\n");
        server->user = true;
        return server->user;
    } else {
        dprintf(server->sd, "530 Login incorrect.\r\n");
        server->user = false;
    }
    return server->user;
}

void pass_cmd(server_t *server)
{
    char password[MAX_USERS];

    if (server->user) {
        sscanf(server->buffer, "%*s %s", password);
        if (strcmp(password, "") == 0) {
            dprintf(server->sd, "230 User logged in, proceed.\r\n");
            server->pass = true;
        } else {
            dprintf(server->sd, "530 Login incorrect.\r\n");
            server->pass = false;
            }
    } else {
        dprintf(server->sd, "503 Login with USER first.\r\n");
        server->pass = false;
    }
}

void help_cmd(server_t *server)
{
    if (server->user && server->pass) {
        dprintf(server->sd, "214 Commands:\nUSER PASS PASV QUIT NOOP PWD\r\n");
    } else
        dprintf(server->sd, "530 Please login with USER and PASS.\r\n");
}
