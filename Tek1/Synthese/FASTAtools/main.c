/*
** EPITECH PROJECT, 2023
** B-SYN-200-PAR-2-1-FASTAtools-luca.martinet
** File description:
** main
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "fast.h"

void init_struct(fast_t *fs)
{
    fs->buf = NULL;
    fs->seq = NULL;
    fs->rest = NULL;
    fs->str = NULL;
    fs->seq = NULL;
    fs->status = 0;
}

int tiret_h(void)
{
    printf("USAGE\n\t./FASTAtools option [k]\nDESCRIPTION\n"
    "\toption 1: read FASTA from the standard input, write the DNA sequen"
    "ces to the \n\t\tstandard output\n"
    "\toption 2: read FASTA from the standard input, write the RNA sequen"
    "ces to the \n\t\tstandard output\n"
    "\toption 3: read FASTA from the standard input, write the reverse com"
    "plement \n\t\tto the standard output\n"
    "\toption 4: read FASTA from the standard input, write the k-mer list "
    "to the \n\t\tstandard output\n"
    "\toption 5: read FASTA from the standard input, write the coding seque"
    "nces \n\t\tlist to the standard output\n"
    "\toption 6: read FASTA from the standard input, write the amino acids l"
    "ist to \n\t\tthe standard output\n"
    "\toption 7: read FASTA from the standard input containing exactly 2 sequ"
    "ences, \n\t\talign them and write the result to the standard output\n"
    "\tk: size of the k-mers for option 4\n");
    return 0;
}

int parse(fast_t *fs, int ac, char **av)
{
    if (atoi(av[1]) >= 1 && atoi(av[1]) <= 7) {
        int check = 0;
        for (int i = 0; i <= ac; i++) {
            switch (av[1][i]) {
            case '1': case1(fs); fs->status = 0; check++; break;
            case '2': case2(fs); fs->status = 0; check++; break;
            case '3': case3(fs); fs->status = 0; check++; break;
            case '4': check++; break;
            case '5': check++; break;
            case '6': check++; break;
            case '7': check++; break;
            }
        } if (check == 0)
            return 84;
    } else
        return 84;
    return 0;
}

int main(int ac, char **av)
{
    if (ac < 2)
        return 84;
    fast_t fs;
    init_struct(&fs);
    if (ac == 2 && !strncmp(av[1], "-h", 2)) {
        tiret_h();
        return 0;
    }
    fs.status = parse(&fs, ac, av);
    free(fs.buf);
    return fs.status;
}
