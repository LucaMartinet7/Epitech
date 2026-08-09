/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD04am-luca.martinet
** File description:
** concat
*/

#include "concat.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void concat_strings(const char *str1, const char *str2, char **res)
{
    int str1_len = strlen(str1);
    int str2_len = strlen(str2);
    int total_len = str1_len + str2_len;
    char *temp = malloc(sizeof(char) * (total_len + 1));
    int a = 0;

    for (int i = 0; i < str1_len; i++) {
        temp[a] = str1[i];
        a++;
    }
    for (int i = 0; i < str2_len; i++) {
        temp[a] = str2[i];
        a++;
    }
    temp[a] = '\0';
    *res = temp;
}

void concat_struct(concat_t *str)
{
    concat_strings(str->str1, str->str2, &str->res);
}
