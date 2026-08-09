/*
** EPITECH PROJECT, 2023
** B-SYN-200-PAR-2-1-projtester-luca.martinet
** File description:
** opt1
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include "../include/test.h"

int get_max_depth(char **arr)
{
    int depth = 0;
    for (int i = 0; arr[i] != NULL; i++)
        depth++;
    return depth - 1;
}

void print_tiret(struct dirent *dir, int depth)
{
    for (int i = 0; i < depth; i++)
        printf("-----");
    printf("%s\n", dir->d_name);
}

void free_dir(struct dirent **dir, int x)
{
    for (int i = 0; i != x; i++)
        free(dir[i]);
    free(dir);
}

void opt_1(char *str, int depth)
{
    struct dirent **dir;
    char *path = NULL;
    int len;
    int x = scandir(str, &dir, 0, alphasort);
    for (int i = 0; i != x; i++) {
        len = (strlen(str) + strlen(dir[i]->d_name) + 2);
        if (dir[i]->d_type == DT_REG)
            print_tiret(dir[i], depth);
        if (dir[i]->d_type == DT_DIR && strncmp(dir[i]->d_name, ".", 1)) {
            print_tiret(dir[i], depth);
            path = malloc(sizeof(char) * (len));
            strncpy(path, str, len);
            strncat(path, "/", len - strlen(path) - 1);
            strncat(path, dir[i]->d_name, len - strlen(path) - 1);
            opt_1(path, depth + 1);
            free(path);
        }
    }
    free_dir(dir, x);
}

void search_trd(test_t *ts, char *str)
{
    ts->title = str_warray(str);

    int i = get_max_depth(ts->title);
    printf("%s\n", ts->title[i]);
    free_func(ts->title);
    opt_1(str, 1);
}
