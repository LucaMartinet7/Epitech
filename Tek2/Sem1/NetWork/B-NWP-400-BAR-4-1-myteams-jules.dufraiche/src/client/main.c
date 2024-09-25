/*
** EPITECH PROJECT, 2024
** B-NWP-400-BAR-4-1-myteams-jules.dufraiche
** File description:
** main
*/

#include <string.h>

#include "client.h"
#include "shared.h"

int main(int ac, char **av)
{
    if (ac == 2 && strcmp(av[1], "-help") == 0)
        return helper();
    if (ac != 3)
        return ERROR;
    if (!is_number(av[2]))
        return ERROR;
    return process_cli(av);
}
