/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 05
*/

#include <stdlib.h>
#include <stdarg.h>
#include "raise.h"
#include "array.h"
#include "new.h"

static void array_iterator_ctor(ArrayIteratorClass *this, va_list *args)
{
    this->_array = va_arg(*args, ArrayClass *);
    this->_idx = va_arg(*args, int);
}

static bool array_iterator_eq(ArrayIteratorClass *this,
    ArrayIteratorClass *other)
{
    return (this->_idx == other->_idx);
}

static bool array_iterator_gt(ArrayIteratorClass *this,
    ArrayIteratorClass *other)
{
    return (this->_idx > other->_idx);
}

static bool array_iterator_lt(ArrayIteratorClass *this,
    ArrayIteratorClass *other)
{
    return (this->_idx < other->_idx);
}

static void array_iterator_incr(ArrayIteratorClass *this)
{
    this->_idx += 1;
}

static object *array_iterator_getval(ArrayIteratorClass *this)
{
    if (this->_idx >= this->_array->_size)
        raise("Out of range");
    return (this->_array->_tab[this->_idx]);
}

/* Fill this function for exercice 05 */
static void array_iterator_setval(ArrayIteratorClass *this, ...)
{
    return;
}
