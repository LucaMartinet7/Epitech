/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 01
*/

#include "new.h"
#include "raise.h"

Object *new(const Class *class, ...)
{
    va_list ap;
    Object *obj;

    va_start(ap, class);
    obj = va_new(class, &ap);
    va_end(ap);
    return (obj);
}

Object *va_new(const Class *class, va_list* ap)
{
    Object *obj;

    if (!class)
        raise("Class is null");
    obj = malloc(class->__size__);
    if (!obj)
        raise("Malloc failed");
    memcpy(obj, class, class->__size__);
    if (class->__ctor__) {
        class->__ctor__(obj, ap);
    }
    return (obj);
}

void delete(Object *ptr)
{
    Class *class = (Class *)ptr;
    if (!ptr)
        raise("Object is null");
    if (class->__dtor__) {
        class->__dtor__(ptr);
    }
    free(ptr);
}
