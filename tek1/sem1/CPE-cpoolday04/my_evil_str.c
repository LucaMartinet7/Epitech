/*
** EPITECH PROJECT, 2022
** evil str
** File description:
** day 4 sad
*/

int my_changethename(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        i += 1;
    }
    return (i);
}

char *my_evil_str(char *str)
{
    int i = 0;
    int a = my_changethename(str);
    char temp;
    while (i < a / 2) {
        temp = str[i];
        str[i] = str[a - i - 1];
        str[a - i - 1] = temp;
        i += 1;
    }
    return (str);
}
