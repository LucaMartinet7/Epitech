/*
** EPITECH PROJECT, 2023
** fridge_program_function
** File description:
** fridge_program_function
*/

#include <stdio.h>
#include "fridge.h"

void init_elements(food_elment_t *food)
{
    food->tomatos = 50;
    food->dough = 50;
    food->onion = 50;
    food->pasta = 50;
    food->olives = 50;
    food->pepper = 50;
    food->ham = 50;
    food->cheese = 50;
}

int disp_fridge(food_elment_t *food)
{
    printf("tomato = %d\n", food->tomatos);
    printf("dough = %d\n", food->dough);
    printf("onion = %d\n", food->onion);
    printf("pasta = %d\n", food->pasta);
    printf("olives = %d\n", food->pepper);
    printf("ham = %d\n", food->ham);
    printf("cheese = %d\n", food->cheese);

    return EXIT_SUCCES;
}

int fridge(void)
{
    food_elment_t food;
    char *str = NULL;
    char **array = NULL;
    init_elements(&food);
    while (1) {
        str = conditional();
        array = my_str_to_word_array(str);
        exec_command(array, &food);
        check_command(array);
    }
    return EXIT_SUCCES;
}
