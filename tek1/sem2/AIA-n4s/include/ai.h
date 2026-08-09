/*
** EPITECH PROJECT, 2023
** B-AIA-200-PAR-2-2-n4s-luca.martinet
** File description:
** ai.h
*/
#ifndef AI_H_
    #define AI_H_

    #include <stdio.h>
    #include <stdlib.h>
    #include <stdarg.h>
    #include <unistd.h>
    #include <string.h>
    #include <time.h>
    #include <sys/wait.h>
    #define MAX_BUF_SIZE 512
typedef struct ai_s {
    float array[32];
    double mid;
} ai_t;

typedef struct s_tab {
    int pos;
    char c;
} tab_t;

void my_putchar(char c);
void my_putstr(const char c);
char **my_str_to_word_array(char *str, char c);
int check_finish(char *str);

#endif /*AI_H_*/
