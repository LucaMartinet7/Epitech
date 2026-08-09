/*
** EPITECH PROJECT, 2022
** str num copy
** File description:
** day 6
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    for (int i = 0; src[i] != '\n' && i < n; i++) {
        dest[i] = src[i];
    }
    return dest;
}
