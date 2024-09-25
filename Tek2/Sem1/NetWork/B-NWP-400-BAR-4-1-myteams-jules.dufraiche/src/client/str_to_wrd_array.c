/*
** EPITECH PROJECT, 2024
** B-NWP-400-BAR-4-1-myteams-jules.dufraiche [WSL: Ubuntu]
** File description:
** str_to_wrd_array
*/

#include <stdlib.h>
#include <string.h>

int count_words(char *str)
{
    int i;
    int len = 0;
    int in_quotes = 0;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '"')
            in_quotes = !in_quotes;
        if (str[i] == ' ' && !in_quotes)
            len++;
    }
    return len + 1;
}

void copy_word(char *dest, char *src, int *k)
{
    int in_quotes = 0;
    int start = *k;

    while ((src[*k] != ' ' || in_quotes) && src[*k] != '\0') {
        if (src[*k] == '"') {
            in_quotes = !in_quotes;
        }
        (*k)++;
    }
    strncpy(dest, src + start, *k - start);
    dest[*k - start] = '\0';
    while (src[*k] == ' ' && !in_quotes) {
        (*k)++;
    }
}

char **str_to_wrd_array(char *str, int *len)
{
    int i = 0;
    int k = 0;
    char **array;

    *len = count_words(str);
    array = malloc(sizeof(char *) * (*len + 1));
    for (i = 0; i < *len; i++) {
        array[i] = malloc(sizeof(char) * strlen(str) + 1);
        copy_word(array[i], str, &k);
    }
    array[i] = NULL;
    return array;
}
