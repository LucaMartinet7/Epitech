/*
** EPITECH PROJECT, 2023
** sorter
** File description:
** sorter
*/

#include "../includes/my.h"

void sort_str1(sort_t *sort_s, char** av)
{
    int i = 0;
    parser(sort_s, av);
    while (i != 127) {
        if (sort_s->text_s[i]->passed_or_not == true) {
	    sort_s->characters_in_str_1 += 1;
	}
	i++;
    }
    printer(sort_s);
}
