/*
** EPITECH PROJECT, 2022
** B-MUL-100-PAR-1-2-myhunter-luca.martinet
** File description:
** mouvement.c
*/

#include "../include/my.h"

void move_lantern(void)
{
    sfClock_create();
    sfTime_asMilliseconds(sfMilliseconds(600));
    sfTime_asMilliseconds(sfMilliseconds(200));
}
