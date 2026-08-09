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

/* Fill this function for exercice 05 */
static void array_ctor(ArrayClass *this, va_list *args)
{
    return;
}

static void array_dtor(ArrayClass *this)
{
    for (unsigned int i = 0; i < this->_size; i++)
        delete(this->_tab[i]);
    free(this->_tab);
}

static size_t array_len(ArrayClass *this)
{
    return (this->_size);
}

static iterator *array_begin(ArrayClass *this)
{
    return (new(ArrayIterator, this, 0));
}

static iterator *array_end(ArrayClass *this)
{
    return (new(ArrayIterator, this, this->_size));
}

/* Fill this function for exercice 05 */
static object *array_getitem(ArrayClass *this, ...)
{
    return;
}

/* Fill this function for exercice 05 */
static void array_setitem(ArrayClass *this, ...)
{
    return;
}

static const ArrayClass _descr = {
    {   /* Container struct */
        {   /* Class struct */
            .__size__ = sizeof(ArrayClass),
            .__name__ = "Array",
            .__ctor__ = (ctor_t)&array_ctor,
            .__dtor__ = (dtor_t)&array_dtor,
            .__str__ = NULL,
            .__add__ = NULL,
            .__sub__ = NULL,
            .__mul__ = NULL,
            .__div__ = NULL,
            .__eq__ = NULL,
            .__gt__ = NULL,
            .__lt__ = NULL,
        },
        .__len__ = (len_t)&array_len,
        .__begin__ = (iter_t)&array_begin,
        .__end__ = (iter_t)&array_end,
        .__getitem__ = (getitem_t)&array_getitem,
        .__setitem__ = (setitem_t)&array_setitem,
    },
    ._type = NULL,
    ._size = 0,
    ._tab = NULL
};

const Class *Array = (const Class *)&_descr;
