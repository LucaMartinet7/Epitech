/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "../includes/my.h"

void text_count(char **av, sort_t *sort_s)
{
    if (av[1] != NULL && av[2] == NULL) {
        sort_str1(sort_s, av);
    }
    int i = 0;
    while (i != 127) {
        free(sort_s->text_s[i]);
        i++;
    }
    free(sort_s);
}

int main(int ac, char** av)
{
    ac = ac;
    sort_t *sort_s = malloc(sizeof(sort_t));
    sort_s->characters_in_str_1 = 0;
    sort_s->characters_in_str_2 = 0;
    int i = 0;
    while (i != 127) {
        sort_s->text_s[i] = malloc(sizeof(text_t));
        sort_s->text_s[i]->passed_or_not = false;
        sort_s->text_s[i]->the_character = ' ';
        sort_s->text_s[i]->number_of_times = 0;
        sort_s->text_s[i]->place = 0;
        sort_s->text_s[i]->present_in_both = false;
        i++;
    }
    text_count(av, sort_s);
    return 0;
}
