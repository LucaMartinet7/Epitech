/*
** EPITECH PROJECT, 2023
** printer
** File description:
** printer
*/

#include "../includes/my.h"

int printer2(int i, int place, sort_t *sort_s)
{
    if (i == 127) {
        i = 0;
        }
        if (sort_s->text_s[i]->passed_or_not == true
            && sort_s->text_s[i]->place == place) {
            printf("%c:%i\n",sort_s->text_s[i]->the_character,
            sort_s->text_s[i]->number_of_times);
            place++;
            if (place == (sort_s->characters_in_str_1 + 1)) {
                return 1;
            }
        }
        i++;
        return 0;
}

int printer(sort_t *sort_s)
{
    int i = 0;
    int place = 1;
    while (1) {
        printer2(i, place, sort_s);
    }
    return 0;
}
