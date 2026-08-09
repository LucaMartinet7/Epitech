/*
** EPITECH PROJECT, 2022
** str copy
** File description:
** day 7
*/

char *my_strcpy(char *dest, char const *stc)
{
    int i = 0;
    while (stc[i] != '\0') {
        dest[i] = stc[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
