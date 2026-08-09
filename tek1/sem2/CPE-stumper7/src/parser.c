/*
** EPITECH PROJECT, 2023
** parser
** File description:
** parser
*/

#include "../includes/my.h"

int parser(sort_t *sort_s, char **av)
{
    int i = 0;
    int place = 1;
    while (av[1][i] != '\0') {
        if (sort_s->text_s[(int)(av[1][i])]->passed_or_not == false) {
            sort_s->text_s[(int)(av[1][i])]->passed_or_not = true;
            sort_s->text_s[(int)(av[1][i])]->place = place;
            place++;
        }
        sort_s->text_s[(int)(av[1][i])]->number_of_times++;
        sort_s->text_s[(int)(av[1][i])]->the_character = av[1][i];
        i++;
    }
    return 0;
}
