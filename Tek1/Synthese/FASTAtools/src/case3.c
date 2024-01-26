/*
** EPITECH PROJECT, 2023
** B-SYN-200-PAR-2-1-FASTAtools-luca.martinet
** File description:
** case3
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/fast.h"

int swap(char **tab, char *tmp, int i, int j)
{
    if (tmp[j] == 'A')
        tab[i][j] = 'T';
    if (tmp[j] == 'G')
        tab[i][j] = 'C';
    if (tmp[j] == 'T')
        tab[i][j] = 'A';
    if (tmp[j] == 'C')
        tab[i][j] = 'G';
    if (tmp[i] == 'N')
        tab[i][j] ='N';
    return (0);
}

char **do_case3(char **tab)
{
    int i = 0;
    int j = 0;
    char *tmp = malloc(sizeof(char) * (strlen(tab[i]) + 1));

    while (tab[i]) {
        tmp = revstr(tab[i]);
        while (tab[i][j]) {
            swap(tab, tmp, i, j);
            j++;
        }
        j = 0;
        i++;
    }
    free(tmp);
    return tab;
}

void free_all(char **arr)
{
    for (int i = 0; arr[i] != NULL; i++)
        free(arr[i]);
    free(arr);
}

int case3(fast_t *fs)
{
    fs->str = read_file();
    get_seq(fs);
    fs->rest = do_case3(get_rest(fs->str));
    for (int i = 0; fs->seq[i] && fs->rest[i]; i++) {
        printf("%s\n", fs->seq[i]);
        printf("%s\n", fs->rest[i]);
    }
    free_all(fs->seq);
    free_all(fs->rest);
    free(fs->str);
    fs->status = 0;
    return 0;
}
