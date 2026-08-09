/*
** EPITECH PROJECT, 2023
** B-AIA-200-PAR-2-2-n4s-luca.martinet
** File description:
** str_to_word_array
*/

#include "../include/ai.h"

char **my_str_to_word_array(char *str, char c) {
    int count = 0;
    char *p = str;
    while (*p != '\0') {
        if (*p == c) {
            count++;
        }
        p++;
    }
    count++;
    char **arr = malloc(sizeof(char*) * count);
    if (arr == NULL) {
        return NULL;
    }
    int i = 0;
    p = strtok(str, &c);
    while (p != NULL) {
        arr[i++] = p;
        p = strtok(NULL, &c);
    }
    arr[i] = NULL;
    return arr;
}

