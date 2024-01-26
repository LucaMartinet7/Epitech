/*
** EPITECH PROJECT, 2023
** get_com
** File description:
** get_com
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "fridge.h"

static char *get_commands(void)
{
    char *buff = NULL;
    size_t bufsize;
    int fd = 0;

    if (isatty(fd) == 1)
        write(fd,"", 1);
    if ((getline(&buff, &bufsize, stdin)) == -1) {
        printf("\n");
        exit(0);
    }
    buff = strtok(buff, "\n");
    return buff;
}

char *conditional(void)
{
    char *buff = get_commands();

    if (buff == NULL) {
        return NULL;
    }
    if (strlen(buff) == 0)
        buff = get_commands();
    return buff;
}

static int my_exit(void)
{
    exit(0);
}

int exec_command(char **array, food_elment_t *food)
{
    if (array == NULL) {
        return EXIT_ERROR;
    }

    if (strcmp(array[0],"disp") == 0 && array[1] != NULL &&
        strcmp(array[1], "fridge") == 0) {
        return disp_fridge(food);
    } else if ((strcmp(array[0], "disp") == 0 && array[1] != NULL &&
                strcmp(array[1], "fridge") != 0) ||
               strcmp(array[0], "disp") == 0 && array[1] == NULL) {
        printf("'disp': Invalid operation\n");
    }

    if (strcmp(array[0], "exit") == 0) {
        my_exit();
    }
    return EXIT_SUCCES;
}

int check_command(char **array)
{
    if (strcmp(array[0],"make") == 0 && array[1] != NULL &&
        strcmp(array[1], "pizza") == 0) {
        return 1;
    } else {
        printf("'%s': meal unknown\n", array[1]);
    }
    return 0;
}
