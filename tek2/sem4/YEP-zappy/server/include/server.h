/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** server header
*/

#ifndef SERVER_H_
    #define SERVER_H_

    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <string.h>
    #include <stdbool.h>
    #include <ctype.h>
    #include <limits.h>
    #include <dirent.h>
    #include <sys/types.h>
    #include <sys/time.h>
    #include <errno.h>
    #include <time.h>

    #define BUFFER_SIZE 1024

typedef struct seconds_s {
    clock_t start;
    double elapsed;
} seconds_t;

typedef struct server_s {
    int fd;
    int socket;
    int read_client;
    int opt;
    int addrlen;
    int team_size;
    int nb_players;
    int width;
    int height;
    int nb_teams;
    int freq;
    int old_nb;
    int *client_sockets;
    char ***map;
    struct sockaddr_in address;
    fd_set readfds;
    seconds_t *clock;
} server_t;

int check_errors(int ac, char **av);
void check_ifs(int condition, const char *message);
server_t *set_value(char **av);
void set_default_map(server_t *server);
void delete_user(server_t *server);
void create_file(server_t *server);
void set_player_pos_begin(server_t *server);
void set_fd(server_t *server, int *max_sd, int *sd);

#endif
