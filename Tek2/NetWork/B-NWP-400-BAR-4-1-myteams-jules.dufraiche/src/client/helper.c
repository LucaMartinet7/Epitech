/*
** EPITECH PROJECT, 2024
** B-NWP-400-BAR-4-1-myteams-jules.dufraiche
** File description:
** handle_cli
*/

#include <stdio.h>

#include "client.h"
#include "shared.h"

int helper(void)
{
    printf("USAGE:\t./myteams_cli ip port\n");
    printf(
        "\tip\tis the server ip address on which the server socket listens\n");
    printf("\tport\tis the port number on which the server socket listens\n");
    return SUCCESS;
}
