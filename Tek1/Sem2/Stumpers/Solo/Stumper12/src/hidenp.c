/*
** EPITECH PROJECT, 2023
** hidenp
** File description:
** hidenp
*/

#include "../include/my.h"
#include <unistd.h>

void find_word(char *str1, char *str2)
{
    int len = my_strlen(str1);
    int x = 0;
    for (int i = 0; str2[i] != '\0'; i++) {
        if (str1[x] == str2[i])
            x++;
    }
    if (x == len)
        write(1, "1\n", 2);
    else
        write(1, "0\n", 2);
}

int main(int ac, char **av)
{
    if (ac != 3) {
        write(2, "Usage: ./hidenp needle haystack\n", 32);
        return 84;
    }
    char *str1 = av[1];
    char *str2 = av[2];
    find_word(str1, str2);
    return 0;
}
