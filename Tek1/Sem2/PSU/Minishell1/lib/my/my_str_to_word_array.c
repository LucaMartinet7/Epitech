/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-2-minishell2-luca.martinet
** File description:
** my_str_to_word_array
*/

#include "../../include/my.h"

static int count_words_in_str(char *str)
{
    int words = 0;
    int spaces = 0;
    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] != ' ' || str[i] != '\t')
            spaces++;
        if ((str[i] == ' ' || str[i] == '\t') &&
        (str[i - 1] != ' ' || str[i - 1] != '\t') && i > 0) {
            words++;
            spaces = 0;
        }
    }
    if (spaces > 0)
        words++;
    return words;
}

static int check_space(char c)
{
    if (c == ' ' || c == '\t')
        return 1;
    return 0;
}

static void get_wordlen(int *words_lens, char *str, int nb_words)
{
    int length = 0;
    int index = 0;

    for (int i = 0; i < my_strlen(str); i++) {
        if (index == nb_words)
            break;
        if (check_space(str[i]) == 0)
            length++;
        if ((str[i] == ' ' || str[i] == '\t') && i > 0 &&
        (str[i] != ' ' || str[i] != '\t')) {
            words_lens[index] = length;
            index++;
            length = 0;
        }
    }
    if (length > 0)
        words_lens[index++] = length;
}

static int remove_spaces(char *str, int x)
{
    while (str[x] == ' ' || str[x] == '\t')
        x++;
    return x;
}

char **my_str_to_word_array(char *str)
{
    int words = count_words_in_str(str);
    int *columns = malloc(sizeof(int) * words);
    char **array = malloc(sizeof(char *) * (words + 1));
    if (check_malloc(array, columns) == NULL)
        return NULL;
    int x = 0;
    get_wordlen(columns, str, words);
    for (int i = 0; i < words; i++) {
        array[i] = malloc(sizeof(char) * (columns[i] + 1));
        for (int j = 0; j < columns[i]; j++) {
            x = remove_spaces(str, x);
            array[i][j] = str[x];
            x++;
        }
        array[i][columns[i]] = '\0';
        x++;
    }
    array[words] = NULL;
    free(columns);
    return array;
}
