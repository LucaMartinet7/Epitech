/*
** EPITECH PROJECT, 2022
** my_putchar.c
** File description:
** putchar
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
