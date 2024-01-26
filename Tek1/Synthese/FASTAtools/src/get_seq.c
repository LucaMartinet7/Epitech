/*
** EPITECH PROJECT, 2023
** B-SYN-200-PAR-2-1-FASTAtools-luca.martinet
** File description:
** get_seq
*/

#include <stdlib.h>
#include "../include/fast.h"

int nb_seq(char *str)
{
    int count = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] == '>')
            count++;
    }
    return count;
}

int seq_size(char *str)
{
    int i = 0;

    for (; str[i] != '\n' && str[i]; i++);
    return i;
}

void copy_sequence(fast_t *fs, int *j, int *x, int i)
{
    int seq_size = 0;

    while (fs->str[i] && fs->str[i] != '\n') {
        fs->seq[*j][seq_size] = fs->str[i];
        i++;
        seq_size++;
    }
    fs->seq[*j][seq_size] = '\0';
    *x = seq_size;
}

void get_seq(fast_t *fs)
{
    fs->seq = malloc(sizeof(char *) * (nb_seq(fs->str) + 1));
    int j = 0;
    int x = 0;

    for (int i = 0; fs->str[i]; i++) {
        fs->seq[j] = malloc(sizeof(char) * (seq_size(fs->str) + 1));
        if (fs->str[i] == '>') {
            x = 0;
            copy_sequence(fs, &j, &x, i);
            j++;
        }
    }
    fs->seq[j] = NULL;
}
