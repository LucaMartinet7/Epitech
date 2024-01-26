/*
** EPITECH PROJECT, 2023
** stumper
** File description:
** stumper
*/

#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>

#ifndef MY_H_
    #define MY_H_
    #define EXIT_ERROR 84

char *open_file(char const *filepath);
int function_gameover_check(char *words, char *my_guess, int essaie);
int process_guess(char letter, char *words, char *my_guess, int essaie);
char *init_guess(char *words);
int end_game(char *words, char *my_guess, int essaie);
int my_hangman(char *file, int essaie);
char *open_and_random_words(char *file);
void display_status(char *guess, int essaie);
void try_guess(char charac, char *words, char *my_guess);
int check_space(char *file);
int my_strlen(char const *str);

#endif
