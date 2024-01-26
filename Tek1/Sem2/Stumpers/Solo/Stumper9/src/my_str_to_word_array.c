/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-2-minishell2-luca.martinet
** File description:
** my_str_to_word_array
*/

#include "../include/my.h"

void print_array(char **map, int lines, int columns)
{
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%c", map[i][j]);
        }
        my_putchar('\n');
    }
}

int count_words_in_str(char *str)
{
    int words = 0;
    for (int i = 0; str[i] < my_strlen(str); i++) {
        words = i;
    }
    return words + 1;
}

char **malloc_array(int lines, int columns)
{
    char **array = malloc(sizeof(char *) * (lines));
    if (array == NULL)
        return NULL;
    for (int i = 0; i < lines; i++) {
        array[i] = malloc(sizeof(char) * (columns));
        if (array[i] == NULL)
            return NULL;
    }
    return array;
}

char **my_str_to_word_array(char *str)
{
    int words = count_words_in_str(str);
    int columns = my_strlen(str) / words;
    char **array = malloc_array(words, columns);
    int x = 0;
    for (int i = 0; i < words; i++) {
        for (int j = 0; j < columns; j++) {
            array[i][j] = str[x];
            x++;
        }
        x++;
    }
    return array;
}
