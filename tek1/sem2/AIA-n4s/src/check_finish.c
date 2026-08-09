/*
** EPITECH PROJECT, 2023
** B-AIA-200-PAR-2-2-n4s-luca.martinet
** File description:
** check_finish
*/

#include "../include/ai.h"

int check_finish(char *str)
{
    char *buf = NULL;
    size_t bufsize = 0;

    if (!strcmp(str, "Track Cleared")) {
        dprintf(1, "CAR_FORWARD:0\n");
        if (getline(&buf, &bufsize, stdin) == -1)
            exit(1);
        dprintf(1, "STOP_SIMULATION\n");
        return 1;
    }
    return 0;
}
