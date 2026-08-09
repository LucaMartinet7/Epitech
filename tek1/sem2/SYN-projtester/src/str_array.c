/*
** EPITECH PROJECT, 2023
** B-SYN-200-PAR-2-1-projtester-luca.martinet
** File description:
** str_array
*/

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include "../include/test.h"

static bool iswordcharacter(char c)
{
    if (c == '/' || c == ' ')
        return false;
    return true;
}

static int count_words(char const *str)
{
    int words = 0;
    int spaces = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (iswordcharacter(str[i]))
            words++;
        if ((!iswordcharacter(str[i])) && (iswordcharacter(str[i - 1]))
            && i > 0) {
            spaces++;
            words = 0;
        }
    }
    if (words > 0)
        spaces++;
    return spaces;
}

static void get_wordlen(int *words_lens, const char *str, int nb_words)
{
    int length = 0;
    int index = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (index == nb_words)
            break;
        if (iswordcharacter(str[i]))
            length++;
        if (!iswordcharacter(str[i]) && i > 0 &&
            (iswordcharacter(str[i - 1]))) {
            words_lens[index] = length;
            index++;
            length = 0;
        }
    } if (length > 0)
        words_lens[index++] = length;
}

static int remove_spaces(const char *str, int x)
{
    while (!iswordcharacter(str[x]))
        x++;
    return x;
}

char **str_warray(const char *str)
{
    int words = count_words(str);
    int *count_columns = malloc(sizeof(int) * words);
    char **array = malloc(sizeof(char *) * (words + 1));
    int x = 0;
    get_wordlen(count_columns, str, words);
    for (int i = 0; i < words; i++) {
        array[i] = malloc(sizeof(char) * (count_columns[i] + 1));
        if (array[i] == NULL)
            return NULL;
        for (int j = 0; j < count_columns[i]; j++) {
            x = remove_spaces(str, x);
            array[i][j] = str[x];
            x++;
        }
        array[i][count_columns[i]] = '\0';
        x++;
    }
    array[words] = NULL;
    free(count_columns);
    return array;
}
