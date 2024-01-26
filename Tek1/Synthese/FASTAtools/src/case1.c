/*
** EPITECH PROJECT, 2023
** B-SYN-200-PAR-2-1-FASTAtools-luca.martinet
** File description:
** case1
*/

#include <stdio.h>
#include "../include/fast.h"

int print_spec(char c, int index)
{
    if (index != 0)
        printf("\n");
    index++;
    printf("%c", c);
    while (c != '\n') {
        c = getchar();
        printf("%c", c);
    }
    return index;
}

void print_rest(char c)
{
    if (check_letter_min_1(c))
        printf("%c", c - 32);
    else if (check_letter_cap_1(c))
        printf("%c", c);
}

int case1(fast_t *fs)
{
    char c = 0;
    int index = 0;
    while (c != EOF) {
        c = getchar();
        if (c == '>')
            index = print_spec(c, index);
        print_rest(c);
    }
    printf("\n");
    fs->status = 0;
    return 0;
}
