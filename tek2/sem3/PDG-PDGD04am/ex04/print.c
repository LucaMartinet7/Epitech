/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD04am-luca.martinet
** File description:
** print
*/

#include <stdio.h>
#include "print.h"

void print_normal(const char *str)
{
    printf("%s\n", str);
}

void print_reverse(const char *str)
{
    int length = 0;

    for (length = 0; str[length] != '\0'; length++);
    for (int i = length - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    printf("\n");
}

void print_upper(const char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            printf("%c", str[i] - 32);
        } else {
            printf("%c", str[i]);
        }
    }
    printf("\n");
}

void print_42(const char *str)
{
    (void)str;
    printf("42\n");
}

void do_action(action_t action, const char *str)
{
    void (*ptr[4])(const char *str) = {print_normal, print_reverse,
        print_upper, print_42};

    ptr[action](str);
}
