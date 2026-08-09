/*
** EPITECH PROJECT, 2022
** lib
** File description:
** lib
*/

#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <dirent.h>
#include <stdarg.h>
#include <string.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>


#pragma once

int my_put_nbr(int nb);
int my_putstr(char *str);
int my_strlen(char *str);
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
int my_ls_l(char **av);
char *date_cp(char *date);
void print_perms(const mode_t mode, struct stat info);
void outplayed_for_l(struct dirent *file, struct stat info);
int block_total(struct dirent *file, struct stat info, char **av);
