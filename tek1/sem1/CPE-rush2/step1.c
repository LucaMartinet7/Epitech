/*
** EPITECH PROJECT, 2022
** step1
** File description:
** count the number of occurence of a letter
*/

#include<unistd.h>
#include"my.h"

int error(int argc, char **argv)
{
    if (argc < 3)
        return 84;
    for (int i = 2; argv[i] != 0; i++){
        if (error2(argv, i) == 84)
            return 84;
    }
    return 0;
}

int error2(char **argv, int i)
{
    int len = my_strlen(argv[i]);
    if (len != 1)
        return 84;
    if (argv[i][0] < 'A' || argv[i][0] > 'Z'
        && argv[i][0] < 'a' || argv[i][0] > 'z')
        return 84;
}

void put_ratio(int ratio)
{
    write(1, "(", 1);
    my_put_nbr(ratio / 100);
    write(1, ".", 1);
    my_put_nbr(ratio % 100);
    if (ratio % 100 == 0)
        write(1, "0", 1);
    write(1, "%", 1);
    write(1, ")", 1);
}

int condition_rush2(char **argv, int n)
{
    char copy = argv[n][0];
    char letter = argv[n][0];
    if (argv[n][0] > 64 && argv[n][0] < 91)
        letter += 32;
    int compteur = 0;
    for (int i = 0; argv[1][i] != '\0'; i++){
        if ( argv[1][i] == letter)
            compteur++;
    }
    int nb_letters = my_strlen_lett(argv[1]);
    int ratio = compteur * 10000 / nb_letters;
    write(1, &copy, 1);
    write(1, ":", 1);
    my_put_nbr(compteur);
    write(1, " ", 1);
    put_ratio(ratio);
    write(1, "\n", 1);
}

int main(int argc, char **argv)
{
    if (error(argc, argv) == 84)
        return 84;
    my_strlowcase(argv[1]);
    for (int n = 2; argv[n] != 0; n++) {
        condition_rush2(argv, n);
    }
}
