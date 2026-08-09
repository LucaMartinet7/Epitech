/*
** EPITECH PROJECT, 2022
** B-PSU-100-PAR-1-2-myls-luca.martinet
** File description:
** my_strcmp.c
*/

int my_strlen(char const *str);

int my_strcmp(char const *s1, char const *s2)
{
    int a = 0;
    int b = 0;

    if (s1 == s2)
        return (0);
    for (int i = 0; s1[i] != '\0'; i++) {
        a = a + s1[i];
    }
    for (int i = 0; s2[i] != '\0'; i++) {
        b = b + s2[i];
    }
    if (a < b)
        return (-1);
    else if (a > b)
        return (1);
    return (0);
}
