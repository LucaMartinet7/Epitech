/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercise 02
*/

#include <stdio.h>
#include "new.h"
#include "point.h"
#include "vertex.h"

int main(void)
{
    object *point = new(Point, 42, -42);
    object *vertex = new(Vertex, 0, 1, 2);

    printf("point = %s\\n", str(point));
    printf("vertex = %s\\n", str(vertex));
    delete(point);
    delete(vertex);
    return (0);
}
