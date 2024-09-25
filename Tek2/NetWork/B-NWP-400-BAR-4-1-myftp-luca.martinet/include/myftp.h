/*
** EPITECH PROJECT, 2024
** B-NWP-400-BAR-4-1-myftp-luca.martinet
** File description:
** myftp
*/

#ifndef MYFTP_H_
    #define MYFTP_H_

    #include <stdio.h>
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <netdb.h>
    #include <string.h>
    #include <stdbool.h>
    #include <sys/select.h>
    #include <errno.h>

    #define MAX_USERS 100
    #define BUFFER_SIZE 1024


typedef struct server_s {
    struct sockaddr_in addr;
    int fd_server;
    int new_socket;
    int client_socket[MAX_USERS];
    int data_socket_fd;
    int opt;
    int activity;
    int addrlen;
    char buffer[BUFFER_SIZE];
    fd_set readfds;
    int max_sd;
    int sd;
    int valread;
    int port;
    int i;
    bool user;
    bool pass;
    char *path;
} server_t;

//server
int start_server(server_t *server);
void accept_new_client(server_t *server);

//utils
void check_ifs(int condition, const char *message);
void set_fd(server_t *server, int i);

//loop
void loop(server_t *server);

//commands
void check_cmds(server_t *server);
void check_cmd(server_t *server, int i);
void quit_cmd(server_t *server, int i);
bool user_cmd(server_t *server);
void pass_cmd(server_t *server);
void help_cmd(server_t *server);
void pwd_cmd(server_t *server);
void passive_cmd(server_t *server, int *data_socket_fd,
    struct sockaddr_in *control_adr);

#endif /* !MYFTP_H_ */
