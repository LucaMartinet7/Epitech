/*
** EPITECH PROJECT, 2022
** my_putstr
** File description:
** displays caracters of a string
*/

void my_putchar(char c);
#include <unistd.h>

int my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++){
        write(1, &str[i], 1);
    }
    return 0;
}
