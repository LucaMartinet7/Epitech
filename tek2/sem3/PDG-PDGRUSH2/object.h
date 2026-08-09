/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exerice 01
*/

#pragma once

#include <sys/types.h>
#include <stdarg.h>
#include <stdbool.h>
#include <string.h>
#include "raise.h"

typedef void object;
typedef void (*ctor_t)(object *this, va_list *args);
typedef void (*dtor_t)(object *this);
typedef char *(*to_string_t)(object *this);
typedef object *(*binary_operator_t)(const object *this, const object *other);
typedef bool (*binary_comparator_t)(const object *this, const object *other);

typedef struct {
    const size_t __size__;       // ex01
    const char *__name__;        // ex01
    ctor_t __ctor__;             // ex01
    dtor_t __dtor__;             // ex01
    to_string_t __str__;         // ex02
    binary_operator_t __add__;   // ex03
    binary_operator_t __sub__;   // ex03
    binary_operator_t __mul__;   // ex04
    binary_operator_t __div__;   // ex04
    binary_comparator_t __eq__;  // ex04
    binary_comparator_t __gt__;  // ex04
    binary_comparator_t __lt__;  // ex04
} Class;

#define STR(o) (((Class *)o)->__str__ != NULL ? ((Class *)o)->__str__(o) : strdup(((Class *)o)->__name__))
#define ADDITION(a, b) ((Class *)a)->__add__(a, b)
#define SUBTRACTION(a, b) ((Class *)a)->__sub__(a, b)
#define MULTIPLICATION(a, b) ((Class *)a)->__mul__(a, b)
#define DIVISION(a, b) ((Class *)a)->__div__(a, b)
#define EQ(a, b) ((Class *)a)->__eq__(a, b)
#define GT(a, b) ((Class *)a)->__gt__(a, b)
#define LT(a, b) ((Class *)a)->__lt__(a, b)
