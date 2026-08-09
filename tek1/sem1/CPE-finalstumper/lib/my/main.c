/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include"../../include/my.h"
#include<unistd.h>
#include<stdio.h>

int largeur(char *buff)
{
    int i;
    for (i = 0; buff[i] != '\n'; i++){
    }
    return i;
}

int hauteur(char *buff)
{
    int comp = 0;
    for (int i = 0; buff[i] != '\0'; i++){
        if (buff[i] == '\n')
            comp++;
    }
    return comp;
}

void rush3(char *buff)
{
    if (buff[0] == 'o'){
        my_putstr("[rush1-1] ");
        my_put_nbr(largeur(buff));
        my_putchar(' ');
        my_put_nbr(hauteur(buff));
    } else if (buff[0] == '*' || buff[0] == '/'){
        my_putstr("[rush1-2] ");
        my_put_nbr(largeur(buff));
        my_putchar(' ');
        my_put_nbr(hauteur(buff));
    } else {
        if (buff[0] == 'A' && buff[largeur(buff) - 1] == 'A'){
        my_putstr("[rush1-3] ");
        my_put_nbr(largeur(buff));
        my_putchar(' ');
        my_put_nbr(hauteur(buff));
        } else
            rush3_bis(buff);
    }
}

void rush3_bis(char *buff)
{
    if (buff[0] == 'A' && buff[my_strlen(buff) - largeur(buff) - 1] == 'A'){
        my_putstr("[rush1-4] ");
        my_put_nbr(largeur(buff));
        my_putchar(' ');
        my_put_nbr(hauteur(buff));
    } else if (buff[0] == 'A' && buff[my_strlen(buff) - 2] == 'A'){
        my_putstr("[rush1-5] ");
        my_put_nbr(largeur(buff));
        my_putchar(' ');
        my_put_nbr(hauteur(buff));
    } else
        rush3_bis_bis(buff);
}

void rush3_bis_bis(char *buff)
{
    if (buff[0] == 'B'){
        my_putstr("[rush1-3] ");
        my_put_nbr(largeur(buff));
        my_putchar(' ');
        my_put_nbr(hauteur(buff));
        my_putstr(" || [rush1-4] ");
        my_put_nbr(largeur(buff));
        my_putchar(' ');
        my_put_nbr(hauteur(buff));
        my_putstr(" || [rush1-5] ");
        my_put_nbr(largeur(buff));
        my_putchar(' ');
        my_put_nbr(hauteur(buff));
    } else
        my_putstr("none");
}
