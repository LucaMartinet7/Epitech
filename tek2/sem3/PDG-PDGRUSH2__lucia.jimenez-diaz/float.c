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
#include "float.h"

typedef struct {
    Class base;
    float value;
} FloatClass;

static void Float_ctor(Object *this, va_list *args)
{
    FloatClass *obj = (FloatClass *)this;
    obj->value = va_arg(*args, double);
}

static void Float_dtor(Object *this)
{
    if (!this)
        raise("Object is null");
}

static char *Float_str(Object *this)
{
    FloatClass *obj = (FloatClass *)this;
    char *str = malloc(sizeof(char) * 20);
    sprintf(str, "<Float (%f)>", obj->value);
    return str;
}

static Object *Float_add(const Object *this, const Object *other)
{
    FloatClass *obj1 = (FloatClass *)this;
    FloatClass *obj2 = (FloatClass *)other;
    return new(Float, obj1->value + obj2->value);
}

static Object *Float_sub(const Object *this, const Object *other)
{
    FloatClass *obj1 = (FloatClass *)this;
    FloatClass *obj2 = (FloatClass *)other;
    return new(Float, obj1->value - obj2->value);
}

static Object *Float_mul(const Object *this, const Object *other)
{
    FloatClass *obj1 = (FloatClass *)this;
    FloatClass *obj2 = (FloatClass *)other;
    return new(Float, obj1->value * obj2->value);
}

static Object *Float_div(const Object *this, const Object *other)
{
    FloatClass *obj1 = (FloatClass *)this;
    FloatClass *obj2 = (FloatClass *)other;
    if (obj2->value == 0) {
        fprintf(stderr, "Error: Division by zero\n");
        exit(0);
    }
    return new(Float, obj1->value / obj2->value);
}

static bool Float_eq(const Object *this, const Object *other)
{
    FloatClass *obj1 = (FloatClass *)this;
    FloatClass *obj2 = (FloatClass *)other;
    return (obj1->value == obj2->value);
}

static bool Float_gt(const Object *this, const Object *other)
{
    FloatClass *obj1 = (FloatClass *)this;
    FloatClass *obj2 = (FloatClass *)other;
    return (obj1->value > obj2->value);
}

static bool Float_lt(const Object *this, const Object *other)
{
    FloatClass *obj1 = (FloatClass *)this;
    FloatClass *obj2 = (FloatClass *)other;
    return (obj1->value < obj2->value);
}

static FloatClass _description = {
    {
        sizeof(FloatClass), "Float",
        &Float_ctor,
        &Float_dtor,
        &Float_str,
        &Float_add,
        &Float_sub,
        &Float_mul,
        &Float_div,
        &Float_eq,
        &Float_gt,
        &Float_lt
    }, 0
};

const Class *Float = (const Class *)&_description;
