/*
** EPITECH PROJECT, 2023
** B-SYN-200-PAR-2-1-projtester-luca.martinet
** File description:
** main
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/test.h"

int tiret_h(void)
{
    printf("USAGE\n"
        "\t./projTester TRD [BFT] [outputFile]\n"
        "DESCRIPTION\n"
        "TRD \t\troot directory of all the tests\n"
        "BFT \t\tbinary file to be tested\n"
        "outputFile \tfile in which the ressult is printed\n");
    return 84;
}

void init_struct(test_t *ts)
{
    ts->status = 0;
    ts->title = NULL;
}

void free_func(char **arr)
{
    for (int i = 0; arr[i] != NULL; i++)
        free(arr[i]);
    free(arr);
}

int main(int ac, char **av)
{
    if (ac == 1)
        return tiret_h();
    test_t ts;
    init_struct(&ts);
    ts.status = parse(&ts, ac, av);
    return ts.status;
}
