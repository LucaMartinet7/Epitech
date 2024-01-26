/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-2-minishell2-luca.martinet
** File description:
** my_str_to_word_array
*/

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

bool check_char(char c)
{
    if ((c >= 'a' && c <= 'z'))
        return true;
    return false;
}

bool check_not(char c)
{
    if (!check_char(c) && !(c >= '0' && c <= '9')
        && !(c >= 'A' && c <= 'Z'))
        return true;
    return false;
}

char capitalize(char c, char n)
{
    if (check_char(c) && check_not(n))
        return c - 32;
    return c;
}

void oe_mgl(int i, char *str, char *arr)
{
    if (check_not(str[i])) {
        arr[i] = str[i];
    } else if (check_char(str[i])) {
        arr[i] = capitalize(str[i], str[i - 1]);
    } else {
        arr[i] = str[i];
    }
}

char *my_strcapitalize_synthesis(char *str)
{
    int j = 0;
    int i = 0;
    for (; str[j] != '\0'; j++);
    char *arr = str;
    if (arr == NULL)
        return NULL;
    for (; str[i] != '\0'; i++) {
        oe_mgl(i, str, arr);
    }
    arr[j + 1] = '\0';
    return arr;
}
