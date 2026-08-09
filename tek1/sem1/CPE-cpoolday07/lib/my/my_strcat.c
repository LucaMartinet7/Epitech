/*
** EPITECH PROJECT, 2022
** str cat
** File description:
** day 7
*/

char *my_strcat(char *dest, char const *src)
{
    int L = my_strlen(dest);
    int a;
    for (a = 0; src[a] != '\0'; a++) {
        dest[L + a] = src[a];
    }
    dest[L + a] = '\0';
    return dest;
}
