/*
** EPITECH PROJECT, 2023
** stumper
** File description:
** stumper
*/

int my_strlen(char const *str)
{
    int nb = 0;

    while (str[nb] != '\0')
        nb++;
    return nb;
}
