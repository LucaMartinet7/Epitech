/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 03
*/

#include <stdio.h>
#include "new.h"
#include "point.h"
#include "vertex.h"

int main(void)
{
    object *p1 = new(Point, 12, 13);
    object *p2 = new(Point, 2, 2);
    object *v1 = new(Vertex, 1, 2, 3);
    object *v2 = new(Vertex, 4, 5, 6);

    printf("%s + %s = %s\n", str(p1), str(p2), str(addition(p1, p2)));
    printf("%s - %s = %s\n", str(p1), str(p2), str(subtraction(p1, p2)));
    printf("%s + %s = %s\n", str(v1), str(v2), str(addition(v1, v2)));
    printf("%s - %s = %s\n", str(v1), str(v2), str(subtraction(v1, v2)));
    return (0);
}
