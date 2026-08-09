/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "point.h"
#include "new.h"
#include "object.h"

typedef struct {
    Class base;
    int x, y;
} PointClass;

static void point_ctor(PointClass *this, va_list *args)
{
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
}

static void point_dtor(PointClass *this)
{
    if (!this)
        raise("PointClass is null");
}

static char *point_str(PointClass *this)
{
    char *str = malloc(100);
    if (str == NULL) {
        return NULL;
    }
    sprintf(str, "<Point (%d, %d)>", this->x, this->y);
    return str;
}

static Object *point_add(const Object *this, const Object *other)
{
    PointClass *p1 = (PointClass *)this;
    PointClass *p2 = (PointClass *)other;
    return new(Point, p1->x + p2->x, p1->y + p2->y);
}

static Object *point_sub(const Object *this, const Object *other)
{
    PointClass *p1 = (PointClass *)this;
    PointClass *p2 = (PointClass *)other;
    return new(Point, p1->x - p2->x, p1->y - p2->y);
}

static const PointClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(PointClass),
        .__name__ = "Point",
        .__ctor__ = (ctor_t)&point_ctor,
        .__dtor__ = (dtor_t)&point_dtor,
        .__str__ = (to_string_t)&point_str,
        .__add__ = (binary_operator_t)&point_add,
        .__sub__ = (binary_operator_t)&point_sub,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0
};

const Class *Point = (const Class *)&_description;
