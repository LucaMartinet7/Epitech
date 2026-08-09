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
#include "int.h"

typedef struct {
    Class base;
    int value;
} IntClass;

static void Int_ctor(Object *this, va_list *args)
{
    IntClass *obj = (IntClass *)this;
    obj->value = va_arg(*args, int);
}

static void Int_dtor(Object *this)
{
    if (!this)
        raise("Object is null");
}

static char *Int_str(Object *this)
{
    IntClass *obj = (IntClass *)this;
    char *str = malloc(sizeof(char) * 20);
    sprintf(str, "<Int (%d)>", obj->value);
    return str;
}

static Object *Int_add(const Object *this, const Object *other)
{
    IntClass *obj1 = (IntClass *)this;
    IntClass *obj2 = (IntClass *)other;
    return new(Int, obj1->value + obj2->value);
}

static Object *Int_sub(const Object *this, const Object *other)
{
    IntClass *obj1 = (IntClass *)this;
    IntClass *obj2 = (IntClass *)other;
    return new(Int, obj1->value - obj2->value);
}

static Object *Int_mul(const Object *this, const Object *other)
{
    IntClass *obj1 = (IntClass *)this;
    IntClass *obj2 = (IntClass *)other;
    return new(Int, obj1->value * obj2->value);
}

static Object *Int_div(const Object *this, const Object *other)
{
    IntClass *obj1 = (IntClass *)this;
    IntClass *obj2 = (IntClass *)other;
    if (obj2->value == 0) {
        fprintf(stderr, "Error: Division by zero\n");
        exit(0);
    }
    return new(Int, obj1->value / obj2->value);
}

static bool Int_eq(const Object *this, const Object *other)
{
    IntClass *obj1 = (IntClass *)this;
    IntClass *obj2 = (IntClass *)other;
    return obj1->value == obj2->value;
}

static bool Int_gt(const Object *this, const Object *other)
{
    IntClass *obj1 = (IntClass *)this;
    IntClass *obj2 = (IntClass *)other;
    return obj1->value > obj2->value;
}

static bool Int_lt(const Object *this, const Object *other)
{
    IntClass *obj1 = (IntClass *)this;
    IntClass *obj2 = (IntClass *)other;
    return obj1->value < obj2->value;
}

static IntClass _description = {
    {
        sizeof(IntClass), "Int", 
        &Int_ctor,
        &Int_dtor,
        &Int_str,
        &Int_add,
        &Int_sub,
        &Int_mul,
        &Int_div,
        &Int_eq,
        &Int_gt,
        &Int_lt
        },0
};

const Class *Int = (const Class *)&_description;

void compareAndDivide(Object *a, Object *b)
{
    if (gt(a, b))
        printf("a > b\n");
    else if (lt(a, b))
        printf("a < b\n");
    else
        printf("a == b\n");
    printf("b / a = %s\n", str(division(b, a)));
}
