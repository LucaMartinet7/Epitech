/*
** EPITECH PROJECT, 2022
** B-PSU-100-PAR-1-2-sokoban-luca.martinet
** File description:
** my.h
*/

#pragma once

#include <curses.h>
#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stddef.h>
#include <stdint.h>
#include <inttypes.h>

typedef struct soko{
    char *buf;
    int y;
    int x;
    char **map;
    char **map_temp;
    int save_x;
    int save_y;
    int columns;
    int lines;
} soko_t;

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


//src
int my_sokoban(soko_t *soko);
int check_nb_players(soko_t *soko);
int check_map(soko_t *soko);


//lib/my
char *my_strdup(const char *str);
int my_strlen(char const *str);
char *my_strcpy(char *dest, char const *src);

//counters
void count_columns(soko_t *soko);
void count_lines(soko_t *soko);


char **malloc_array(soko_t *soko);
char **map_in_array(soko_t *soko);

char *open_file(char const *filepath);


void empty_the_map(soko_t *soko);
void print_array(soko_t *soko, char **map);


int map_to_doulbe_char(soko_t *soko);

int sokoban_loop(soko_t *soko);
void cases(soko_t *soko, int key);
