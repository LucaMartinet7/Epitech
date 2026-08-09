/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "point.h"
#include "new.h"
#include "raise.h"
#include "vertex.h"

typedef struct {
    Class base;
    int x, y, z;
} VertexClass;

static void vertex_ctor(VertexClass *this, va_list *args)
{
    if (!this || !args)
        raise("VertexClass is null");
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
    this->z = va_arg(*args, int);
}

static void vertex_dtor(VertexClass *this)
{
    if (!this)
        raise("VertexClass is null");
}

static char *vertex_str(VertexClass *this)
{
    char *str = malloc(100);
    if (str == NULL) {
        return NULL;
    }
    sprintf(str, "<Vertex (%d, %d, %d)>", this->x, this->y, this->z);
    return str;
}

static Object *vertex_add(const Object *this, const Object *other)
{
    VertexClass *v1 = (VertexClass *)this;
    VertexClass *v2 = (VertexClass *)other;
    return new(Vertex, v1->x + v2->x, v1->y + v2->y, v1->z + v2->z);
}

static Object *vertex_sub(const Object *this, const Object *other)
{
    VertexClass *v1 = (VertexClass *)this;
    VertexClass *v2 = (VertexClass *)other;
    return new(Vertex, v1->x - v2->x, v1->y - v2->y, v1->z - v2->z);
}

static const VertexClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(VertexClass),
        .__name__ = "Vertex",
        .__ctor__ = (ctor_t)&vertex_ctor,
        .__dtor__ = (dtor_t)&vertex_dtor,
        .__str__ = (to_string_t)&vertex_str,
        .__add__ = (binary_operator_t)&vertex_add,
        .__sub__ = (binary_operator_t)&vertex_sub,
    },
    .x = 0,
    .y = 0,
    .z = 0
};

const Class *Vertex = (const Class *)&_description;
