/*
** EPITECH PROJECT, 2022
** strn cat
** File description:
** day 7
*/

char *my_strncat(char *dest, char const *src, int nb)
{
    int length = my_strlen(dest) - my_strlen(dest - nb);
    for (int i = 0; src[i] != '\0'; i++) {
        dest[length + i] = src[i];
    }
    dest[length + i] = '\0';
    return dest;
}
