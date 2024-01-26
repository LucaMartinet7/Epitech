/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** my.h
*/

#include <sys/wait.h>
#include <stdio.h>
#include <dirent.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <stdbool.h>

#ifndef MY_H_
    #define MY_H_

typedef struct text_s {
    char the_character;
    int number_of_times;
    int place;
    bool passed_or_not;
    bool present_in_both;
} text_t;

typedef struct sort_s {
    text_t *text_s[127];
    int characters_in_str_1;
    int characters_in_str_2;
} sort_t;

int printer(sort_t *sort_s);
int parser(sort_t *sort_s, char **av);
void sort_str1(sort_t *sort_s, char** av);

#endif
