/*
** EPITECH PROJECT, 2023
** include
** File description:
** include
*/

#include <stdlib.h>

#ifndef FRIDGE_H_
    #define FRIDGE_H_
    #define EXIT_ERROR 84
    #define EXIT_SUCCES 0
    #define MAX_SIZE_ARG 1

typedef struct food_elements_s {
    int tomatos;
    int dough;
    int onion;
    int pasta;
    int olives;
    int pepper;
    int ham;
    int cheese;
} food_elment_t;

int fridge(void);
int disp_fridge(food_elment_t *food);
char *conditional(void);
int check_command(char **array);
int exec_command(char **array, food_elment_t *food);
void *check_malloc(char **array, int *columns);
char **my_str_to_word_array(char *str);
int my_strlen(char const *str);
#endif
