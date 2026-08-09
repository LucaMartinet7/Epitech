/*
** EPITECH PROJECT, 2022
** strn cat
** File description:
** day 7
*/

char *my_strncat(char *dest, char const *src, int nb)
{
    int L = my_strlen(dest);
    int a;
    for (a = 0; src[a] != src[nb]; a++) {
        dest[L + a] = src[a];
    }
    dest[L + a] = '\0';
    return dest;
}
