/*
** EPITECH PROJECT, 2022
** B-BOO-101-PAR-1-1-phoenixd03-noe.kurata
** File description:
** my_putchar.c
*/

#include "../include/my_printf.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
