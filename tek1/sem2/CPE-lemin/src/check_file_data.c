/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-2-lemin-luca.martinet
** File description:
** check_file_data
*/

#include "../include/lem.h"
#include "../lib/my/my.h"
#include <string.h>
#include <stdlib.h>

char **check_file_data(char *file, int lines)
{
    char **file_data = malloc(sizeof(char *) * (lines + 1));
    for (int i = 0; i < lines; i = i + 1) {
        int len = strcspn(file, "\n");
        file_data[i] = malloc(sizeof(char) * (len + 1));
        my_strncpy(file_data[i], file, len);
        file += len + 1;
    }
    file_data[lines] = 0;
    return file_data;
}
