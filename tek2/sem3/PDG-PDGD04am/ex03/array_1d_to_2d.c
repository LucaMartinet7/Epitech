/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD04am-luca.martinet
** File description:
** array_1d_to_2d
*/

#include <stdio.h>
#include <stdlib.h>

void array_1d_to_2d(const int *array, size_t height, size_t width, int ***res)
{
    int **temp = malloc(sizeof(int *) * height);
    int a = 0;

    for (int i = 0; i < height; i++) {
        temp[i] = malloc(sizeof(int) * width);
        for (int j = 0; j < width; j++) {
            temp[i][j] = array[a];
            a++;
        }
    }
    *res = temp;
}

void array_2d_free(int **array, size_t height, size_t width)
{
    for (int i = 0; i < height; i++) {
        free(array[i]);
    }
    free(array);
}
