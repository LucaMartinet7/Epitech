/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Set server struct value Zappy
*/

#include "server.h"
#include "resources.h"

void set_clock(server_t *server)
{
    server->clock = malloc(sizeof(clock_t));
    server->clock->start = clock();
    server->clock->elapsed = 0;
}

void get_team_nb(server_t *server, char **av)
{
    int found = 0;

    server->nb_teams = 0;
    for (int i = 0; strcmp(av[i], "-c") != 0; i++) {
        if (strcmp(av[i], "-n") == 0) {
            found = 1;
        }
        if (found == 1) {
            server->nb_teams++;
        }
    }
}

void set_ressources(void)
{
    resources_t *resources = malloc(sizeof(resources_t));

    resources->food = 0.05;
    resources->linemate = 0.3;
    resources->deraumere = 0.15;
    resources->sibur = 0.1;
    resources->mendiane = 0.1;
    resources->phiras = 0.08;
    resources->thystame = 0.05;
}

void value_settings(server_t *server, char **av)
{
    get_team_nb(server, av);
    set_ressources();
    set_default_map(server);
    set_clock(server);
}

server_t *set_value(char **av)
{
    server_t *server = malloc(sizeof(server_t));

    server->opt = 1;
    server->nb_players = 0;
    server->addrlen = sizeof(server->address);
    for (int i = 0; av[i] != NULL; i++) {
        if (strcmp(av[i], "-c") == 0)
            server->team_size = atoi(av[i + 1]);
        if (strcmp(av[i], "-x") == 0)
            server->width = atoi(av[i + 1]);
        if (strcmp(av[i], "-y") == 0)
            server->height = atoi(av[i + 1]);
        if (strcmp(av[i], "-f") == 0)
            server->freq = atoi(av[i + 1]);
    }
    server->client_sockets = malloc(sizeof(int) * server->team_size);
    value_settings(server, av);
    return (server);
}
