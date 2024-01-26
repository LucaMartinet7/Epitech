/*
** EPITECH PROJECT, 2023
** B-CPE-110-PAR-1-2-antman-luca.martinet
** File description:
** my_str2wordarray.c
*/

#include "../include/my_printf.h"

char** my_str2wordarray(char* string)
{
    int num_words = 1;
    for (int i = 0; i < my_strlength(string); i++) {
        if (string[i] == ' ') {
            num_words++;
        }
    }
    char** words = (char**) malloc(num_words * sizeof(char*));
    int start = 0;
    int word_index = 0;
    for (int i = 0; i < my_strlength(string); i++) {
        if (string[i] == ' ') {
            int word_length = i - start;
            words[word_index] = (char*) malloc((word_length + 1) * sizeof(char));
            my_strncpy(words[word_index], string + start, word_length);
            words[word_index][word_length] = '\0';
            start = i + 1;
            word_index++;
        }
    }
    int word_length = my_strlength(string) - start;
    words[word_index] = (char*) malloc((word_length + 1) * sizeof(char));
    my_strncpy(words[word_index], string + start, word_length);
    words[word_index][word_length] = '\0';
    return words;
}

