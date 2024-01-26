/*
** EPITECH PROJECT, 2023
** B-SYN-200-PAR-2-1-projtester-luca.martinet
** File description:
** array
*/

#include <stddef.h>
#include <stdlib.h>
#include "../include/test.h"

int my_strlen(char *str)
{
    int i = 0;
    for (; str[i] != '\0'; i++);
    return i;
}

static void paths_len(int *paths_lens, char *str, int nb_paths)
{
    int length = 0;
    int x = 0;

    for (int i = 0; i < my_strlen(str); i++) {
        if (x == nb_paths)
            break;
        if (str[i] != ':')
            length++;
        if (str[i] == ':' && i > 0 && str[i - 1] != ':') {
            paths_lens[x] = length;
            x++;
            length = 0;
        }
    }
    if (length > 0)
        paths_lens[x++] = length;
}

static int paths_total(char *str)
{
    int nb_paths = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ':')
            nb_paths++;
    }
    return nb_paths + 1;
}

static int remove_colons(char *str, int x)
{
    while (str[x] == ':')
        x++;
    return x;
}

char **get_path_array(char *path_env)
{
    char *str = path_env + 5;
    int nb_paths = paths_total(str);
    int path_len[nb_paths];
    int x = 0;
    paths_len(path_len, str, nb_paths);
    char **array = malloc(sizeof(char *) * (nb_paths + 1));
    if (array == NULL)
        return NULL;
    for (int i = 0; i < nb_paths; i++) {
        array[i] = malloc(sizeof(char) * (path_len[i] + 1));
        for (int j = 0; j < path_len[i]; j++) {
            x = remove_colons(str, x);
            array[i][j] = str[x];
            x++;
        }
        array[i][path_len[i]] = '\0';
    }
    array[nb_paths] = NULL;
    return array;
}
