/*
** EPITECH PROJECT, 2022
** B-CPE-110-PAR-1-2-BSQ-luca.martinet
** File description:
** my.h
*/

#pragma once

#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <time.h>

//lib/my
int my_put_nbr(int nb);
int my_strlen(char const *str);
int my_getnbr(char *str);
void my_putchar(char c);
int int_to_bin(int nb);
int int_to_oct(int nb);
int my_put_u(unsigned int nb);
int int_to_hex(int nb);
int my_put_e(int number, int maj);
int int_to_x_lower(int nb);
int int_to_x_upper(int nb);
int my_printf(const char *restrict format, ...);
char *my_strdup(const char *str);
int my_strcmp(char const *s1, char const *s2);
int my_putstr(char const *str);
