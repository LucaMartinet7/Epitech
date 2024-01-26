/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-2-lemin-luca.martinet
** File description:
** help
*/

#include "../include/lem.h"
#include "../lib/my/my.h"
#include <unistd.h>

int help(void)
{
    write(1, "USAGE\n\t./lemin\n\n", 17);
    write(1, "DESCRIPTION\n\t", 13);
    write(1, "The project consists of finding the shortest path ", 49);
    write(1, "between the start and the end of the anthill.\n\t", 47);
    write(1, "The anthill is represented by a graph.\n\t", 40);
    write(1, "The first line of the file contains the number of ants.\n\t", 56);
    write(1, "The following lines represent the rooms of the anthill.\n\t", 56);
    write(1, "The rooms are represented by: name coord_x coord_y\n\t", 51);
    write(1, "The links are represented by: name1-name2\n\t", 42);
    write(1, "The start room is represented by the command ##start\n\t", 54);
    write(1, "The end room is represented by the command ##end\n\n", 48);
    return 0;
}
