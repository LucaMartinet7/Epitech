/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 05
*/

#pragma once

#include "container.h"

extern const Class *Array;

typedef struct {
    container base;
    Class *_type;
    size_t _size;
    object **_tab;
} ArrayClass;

typedef struct {
    iterator base;
    ArrayClass *_array;
    size_t _idx;
} ArrayIteratorClass;

static const ArrayIteratorClass ArrayIteratorDescr = {
    {   /* Iterator struct */
        {   /* Class struct */
            .__size__ = sizeof(ArrayIteratorClass),
            .__name__ = "ArrayIterator",
            .__ctor__ = (ctor_t)&array_iterator_ctor,
            .__dtor__ = NULL,
            .__str__ = NULL,
            .__add__ = NULL,
            .__sub__ = NULL,
            .__mul__ = NULL,
            .__div__ = NULL,
            .__eq__ = (binary_comparator_t)&array_iterator_eq,
            .__gt__ = (binary_comparator_t)&array_iterator_gt,
            .__lt__ = (binary_comparator_t)&array_iterator_lt,
        },
        .__incr__ = (incr_t)&array_iterator_incr,
        .__getval__ = (getval_t)&array_iterator_getval,
        .__setval__ = (setval_t)&array_iterator_setval,
    },
    ._array = NULL,
    ._idx = 0
};

static const Class *ArrayIterator = (const Class *)&ArrayIteratorDescr;
