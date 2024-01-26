/*
** EPITECH PROJECT, 2023
** B-SYN-200-PAR-2-1-FASTAtools-luca.martinet
** File description:
** rest3
*/

#include <stdlib.h>
#include <string.h>
#include "../include/fast.h"

bool lower_case(char c)
{
    return (c == 'a' || c == 'c' || c == 'g' || c == 't' || c == 'n')
    ? true : false;
}

bool upper_case(char c)
{
    return (c == 'A' || c == 'C' || c == 'G' || c == 'T' || c == 'N')
    ? true : false;
}

int skip_sequence(char *str, int *i)
{
    while (str[*i] && str[*i] != '\n')
        (*i)++;
    return 0;
}

int process_sequence(char **arr, char *str, int *i, int *j)
{
    int k = 0;

    while (str[*i] && str[*i] != '>') {
        if (lower_case(str[*i]) || upper_case(str[*i]))
            arr[*j][k++] = capitalize(str[*i]);
        (*i)++;
    }
    arr[*j][k] = '\0';
    (*j)++;
    return 0;
}

char **get_rest(char *str)
{
    int i = 0;
    int j = 0;

    char **arr = malloc(sizeof(char *) * (nb_seq(str) + 1));
        if (arr == NULL)
        return NULL;
    while (str[i]) {
        arr[j] = malloc(sizeof(char) * (strlen(str) + 1));
            if (arr[j] == NULL)
            return NULL;
        if (str[i] == '>') {
            skip_sequence(str, &i);
        } if (str[i] && str[i] != '>') {
            process_sequence(arr, str, &i, &j);
        } if (str[i])
            i++;
    }
    arr[j] = NULL;
    return arr;
}
