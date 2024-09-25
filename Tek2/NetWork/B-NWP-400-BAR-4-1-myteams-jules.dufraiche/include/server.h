/*
** EPITECH PROJECT, 2024
** B-NWP-400-BAR-4-1-myteams-jules.dufraiche
** File description:
** server
*/

#include <signal.h>
#include <sys/select.h>
#include <netinet/in.h>

#include "shared.h"

#ifndef _SERVER_H
    #define _SERVER_H

    #define BUFFER_SIZE 1024

typedef struct msg_s {
    char sender_uuid[40];
    char receiver_uuid[40];
    char msg[MAX_BODY_LENGTH + 1];
    time_t timestamp;
    struct message_s *next;
} msg_t;

typedef struct msg_list_s {
    msg_t *head;
    int n;
} msg_list_t;

typedef struct user_s {
    char name[40];
    char uuid[40];
    bool is_connected;
    bool was_connected;
} user_t;

typedef struct server_s {
    int server_fd;
    int new_socket;
    int port;
    fd_set readfds;
    int max_sd;
    int max_clients[MAX_CLIENTS];
    int clisock[MAX_CLIENTS];
    user_t users[MAX_CLIENTS];
    msg_list_t *messages;
    struct sockaddr_in server_addr;
    int addrlen;
} server_t;

static volatile sig_atomic_t open = 1;

/*Server utils*/
server_t *init_server(char **av);
void destroy_server(server_t *server);

/*Server connections*/
void manage_connection(server_t *server);
void set_fd(server_t *server, int i);
void remove_user(server_t *server, int i);

/*Handle server*/
int handle_server(int ac, char **av);

/*Process*/
int process_server(char **av);

/*Start server*/
int start_server(server_t *server);

#endif /* !_SERVER_H */
