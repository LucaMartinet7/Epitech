/*
** EPITECH PROJECT, 2022
** my strcmp
** File description:
** strcmp
*/

int my_strcmp(char const *s1, char const *s2)
{
    for (int i = 0; ; i++) {
        if (s1[i] == '\0' && s2[i] == '\0')
            return 0;
        int size1 = (int) s1[i];
        int size2 = (int) s2[i];
        if (size1 > size2)
            return 1;
        if (size1 < size2)
            return -1;
    }
}
