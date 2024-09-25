/*
** EPITECH PROJECT, 2024
** B-NWP-400-BAR-4-1-myteams-jules.dufraiche
** File description:
** client
*/

#include <stdbool.h>
#include <signal.h>

#ifndef _CLIENT_H_
    #define _CLIENT_H_

    #define BUFFERSIZE 1024

typedef struct client_s {
    bool connected;
    char *name;
    char *uuid;
    int sockFd;
    int port;
    char *ip;
    char line[BUFFERSIZE];
    char *command;
} client_t;

static volatile sig_atomic_t open = 1;

/*helper*/
int helper(void);

/*Process*/
int process_cli(char **av);
void process_input(client_t *client);

/*Client utils*/
client_t *init_client(char **av);
void destroy_client(client_t *client);


/*Run client*/
int start_client(client_t *client);
void read_server(client_t *client);

char **str_to_wrd_array(const char *str, int *tab_size);

int client_event_logged_out(char const *user_uuid, const char *user_name);
int client_error_already_exist(void);
int client_error_unauthorized(void);

/*Command utils*/
void free_array(char **array, int len);
void handle_login(char *message, client_t *client);
void handle_logout(char *message, client_t *client);
void handle_help(char *message, client_t *client);
typedef void (*command_handler_t)(char *message, client_t *client);

typedef struct {
    const char *name;
    command_handler_t handler;
} command_t;


#endif /* !_CLIENT_H_ */
