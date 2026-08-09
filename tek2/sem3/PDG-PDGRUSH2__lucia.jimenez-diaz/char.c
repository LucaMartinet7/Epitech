/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 04
*/

#include <stdio.h>
#include "new.h"
#include "point.h"
#include "vertex.h"
#include "char.h"

typedef struct
{
    Class base;
    char value;
} CharClass;

static void Char_ctr(Object *this, va_list *args)
{
    CharClass *obj = (CharClass *)this;
    obj->value = va_arg(*args, int);
}

static void Char_dtor(Object *this)
{
    if (!this)
        raise("Object is null");
}

static char *Char_str(Object *this)
{
    CharClass *obj = (CharClass *)this;
    char *str = malloc(sizeof(char) * 20);
    sprintf(str, "<Char (%c)>", obj->value);
    return str;
}

static Object *Char_add(const Object *this, const Object *other)
{
    CharClass *obj1 = (CharClass *)this;
    CharClass *obj2 = (CharClass *)other;
    return new(Char, obj1->value + obj2->value);
}

static Object *Char_sub(const Object *this, const Object *other)
{
    CharClass *obj1 = (CharClass *)this;
    CharClass *obj2 = (CharClass *)other;
    return new(Char, obj1->value - obj2->value);
}

static Object *Char_mul(const Object *this, const Object *other)
{
    CharClass *obj1 = (CharClass *)this;
    CharClass *obj2 = (CharClass *)other;
    return new(Char, obj1->value * obj2->value);
}

static Object *Char_div(const Object *this, const Object *other)
{
    CharClass *obj1 = (CharClass *)this;
    CharClass *obj2 = (CharClass *)other;
    if (obj2->value == 0) {
        fprintf(stderr, "Error: Division by zero\n");
        return NULL;
    }
    return new(Char, obj1->value / obj2->value);
}

static bool Char_eq(const Object *this, const Object *other)
{
    CharClass *obj1 = (CharClass *)this;
    CharClass *obj2 = (CharClass *)other;
    return (obj1->value == obj2->value);
}

static bool Char_gt(const Object *this, const Object *other)
{
    CharClass *obj1 = (CharClass *)this;
    CharClass *obj2 = (CharClass *)other;
    return (obj1->value > obj2->value);
}

static bool Char_lt(const Object *this, const Object *other)
{
    CharClass *obj1 = (CharClass *)this;
    CharClass *obj2 = (CharClass *)other;
    return (obj1->value < obj2->value);
}

static CharClass _description = {
    {
        sizeof(CharClass), "Char",
        &Char_ctr, &Char_dtor,
        &Char_str, &Char_add, &Char_sub, &Char_mul, &Char_div,
        &Char_eq, &Char_gt, &Char_lt
    }, 0
};

const Class *Char = (const Class *)&_description;
