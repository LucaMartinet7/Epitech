/*
** EPITECH PROJECT, 2022
** put str
** File description:
** day 7
*/

int my_putstr(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        my_putchar(str[i]);
        i += 1;
    }
}
