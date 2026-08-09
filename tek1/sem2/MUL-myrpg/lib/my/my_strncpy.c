/*
** EPITECH PROJECT, 2022
** *my_strncpy.c
** File description:
** n copie
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    for (; i < n; i++ ) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}
