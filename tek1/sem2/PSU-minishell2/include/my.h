/*
** EPITECH PROJECT, 2022
** B-PSU-200-PAR-2-2-bsminishell1-luca.martinet
** File description:
** my.h
*/

#pragma once
#include "mysh.h"

//lib/my
int my_put_nbr(int nb);
int my_strlen(char const *str);
int my_getnbr(char *str);
void my_putchar(char c);
int int_to_bin(int nb);
int int_to_oct(int nb);
int my_put_u(unsigned int nb);
int int_to_x_lower(int nb);
int int_to_x_upper(int nb);
int my_printf(const char *restrict format, ...);
char *my_strdup(const char *str);
int my_strcmp(char const *s1, char const *s2);
int my_putstr(char const *str);
char **my_str_to_word_array(char *str);
void print_array_single(char **map);
int my_strncmp(char const *s1 , char const *s2, int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strcat(char *dest, char const *src);
char **my_str_array_dup(char **array_cpy);
void *check_malloc(char **array, int *columns);
char *my_cat_raf(char *src1, char *src2);
void for_free(char **array);
char **my_str_word_array_sep(char *str, char c);
