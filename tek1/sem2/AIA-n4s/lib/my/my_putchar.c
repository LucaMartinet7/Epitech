/*
** EPITECH PROJECT, 2023
** B-AIA-200-PAR-2-2-n4s-luca.martinet
** File description:
** my_putchar.c
*/
#include <unistd.h>
void my_putchar(char c)
{
    write(1, &c, 1);
}
