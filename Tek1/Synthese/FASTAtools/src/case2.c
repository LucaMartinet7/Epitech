/*
** EPITECH PROJECT, 2023
** B-SYN-200-PAR-2-1-FASTAtools-luca.martinet
** File description:
** case2
*/

#include <stdlib.h>
#include <stdio.h>
#include "../include/fast.h"

int print_spec2(char c, int index)
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

void print_rest2(char c)
{
    if (check_letter_min_2(c))
        printf("%c", c - 32);
    if (c == 'T' || c == 't')
        printf("%c", 'U');
    else if (check_letter_cap_1(c))
        printf("%c", c);
}

int case2(fast_t *fs)
{
    char c = 0;
    int index = 0;
    while (c != EOF) {
        c = getchar();
        if (c == '>')
            index = print_spec2(c, index);
        print_rest2(c);
    }
    printf("\n");
    fs->status = 0;
    return 0;
}
