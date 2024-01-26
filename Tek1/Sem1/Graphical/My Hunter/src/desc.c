/*
** EPITECH PROJECT, 2022
** B-MUL-100-PAR-1-2-myhunter-luca.martinet
** File description:
** desc.c
*/

#include "../include/my.h"

void description(void)
{
    my_printf("My Hunter\n");
    my_printf("\n");
    my_printf("USAGE\n");
    my_printf("./my_hunter without option to launch game\n");
    my_printf("\n");
    my_printf("DESCRIPTION\n");
    my_printf("The goal of the game is to collect ");
    my_printf("as many lanters as possible.\n");
    my_printf("Each lantern caught gives one point.\n");
    my_printf("Don't miss them or you'll loose one life.\n");
    my_printf("Loose all 3 lives and it's game over.\n");
}
