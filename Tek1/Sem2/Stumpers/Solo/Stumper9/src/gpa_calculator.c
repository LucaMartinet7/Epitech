/*
** EPITECH PROJECT, 2023
** gpa calc
** File description:
** gpa calc
*/

#include "../include/my.h"

int first_switch(char *comp, int j, int value)
{
    switch(comp[j]) {
    case 'A': value = 4; break;
    case 'B': value = 3; break;
    case 'C': value = 2; break;
    case 'D': value = 1; break;
    case 'E': value = 0; break;
    }
    return value;
}

int get_credits(char **av, int ac)
{
    int num = 0;
    for (int i = 1; i < ac; i++) {
        for (int j = 0; j < 3; j++) {
            if (av[i][j] >= 48 && av[i][j] <= 57) {
                num = av[i][j];
            }
            else
                j++;
        }
        printf("%d\n", num);
        num_total = num_total + num;
    }
    return num_total;
}

int get_points(char **av, int ac)
{
    int points = 0;
    char *comp = NULL;
    char *tmp = NULL;
    for (int i = 1; i < ac; i++) {
	tmp = strtok(av[i], ",");                                                                              
        comp = tmp;
        for (int j = 0; j < 1; j++) {
            points = first_switch(comp, j, points);
        }
        printf("points: %d\n", points);
        points_total = points_total + points
    }
    return total_total;
}

int main(int ac, char **av)
{
    if (ac < 1)
        return 84;
    int boucle = 1;
    int points = 0;
    int credits = 0;
    int total = 0;
    total_points = get_points(av, ac);
    return 0;
}
