/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** server header
*/

#pragma once

#include "player.h"

typedef void (*command_handler_t)(int fd, server_t *server, player_t **player);

typedef struct command_s {
    char *command;
    command_handler_t handler;
} command_t;


void handle_forward(int fd, server_t *server, player_t **player);
void handle_right(int fd, server_t *server, player_t **player);
void handle_left(int fd, server_t *server, player_t **player);
void handle_look(int fd, server_t *server, player_t **player);
void handle_inventory(int fd, server_t *server, player_t **player);
void handle_broadcast(int fd, server_t *server, player_t **player);
void handle_connect(int fd, server_t *server, player_t **player);
void handle_fork(int fd, server_t *server, player_t **player);
void handle_eject(int fd, server_t *server, player_t **player);
void handle_pick_up(int fd, server_t *server, player_t **player);
void handle_set_obj(int fd, server_t *server, player_t **player);
void handle_incantation(int fd, server_t *server, player_t **player);

command_t command_mappings[] = {
    {"Forward\n", handle_forward},
    {"Right\n", handle_right},
    {"Left\n", handle_left},
    {"Look\n", handle_look},
    {"Inventory\n", handle_inventory},
    {"Broadcast text\n", handle_broadcast},
    {"Connect_nbr\n", handle_connect},
    {"Fork\n", handle_fork},
    {"Eject\n", handle_eject},
    {"Take object\n", handle_pick_up},
    {"Set object\n", handle_set_obj},
    {"Incantation\n", handle_incantation},
    {NULL, NULL}
};
