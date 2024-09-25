/*
** EPITECH PROJECT, 2024
** B-NWP-400-BAR-4-1-myftp-luca.martinet
** File description:
** passive_cmd
*/

#include <time.h>
#include <stdlib.h>
#include "myftp.h"

static void create_data_socket(int *data_socket_fd,
    struct sockaddr_in *pasv_addr, unsigned int port)
{
    *data_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (*data_socket_fd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    pasv_addr->sin_port = htons(port);
    if (bind(*data_socket_fd, (struct sockaddr *)
        pasv_addr, sizeof(*pasv_addr)) < 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }
    if (listen(*data_socket_fd, 1) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
}

void send_pasv_response(server_t *server,
    struct sockaddr_in *pasv_addr, unsigned int port)
{
    char reply[BUFFER_SIZE];
    char *ipstr = inet_ntoa(pasv_addr->sin_addr);

    sprintf(reply, "227 Entering Passive Mode (%s,%d,%d).\r\n",
        ipstr, port / 256, port % 256);
    dprintf(server->sd, "%s", reply);
}

void passive_cmd(server_t *server, int *data_socket_fd,
    struct sockaddr_in *control_adr)
{
    struct sockaddr_in pasv_addr = *control_adr;
    unsigned int port = rand() % (65535 - 1024) + 1024;

    if (server->user && server->pass) {
        create_data_socket(data_socket_fd, &pasv_addr, port);
        send_pasv_response(server, &pasv_addr, port);
    }
}
