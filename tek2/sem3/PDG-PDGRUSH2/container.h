/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 05
*/

#pragma once

#include "object.h"
#include "iterator.h"
#include "raise.h"

typedef struct Container_s container;

typedef iterator *(*iter_t)(container *this);
typedef size_t (*len_t)(container *this);
typedef object *(*getitem_t)(container *this, ...);
typedef void (*setitem_t)(container *this, ...);

struct Container_s {
    Class base;
    len_t __len__;
    iter_t __begin__;
    iter_t __end__;
    getitem_t __getitem__;
    setitem_t __setitem__;
};

#define LEN(c) ((container *)c)->__len__(c)
#define BEGIN(c) ((container *)c)->__begin__(c)
#define END(c) ((container *)c)->__end__(c)
#define GETITEM(c, ...)((container *)c)->__getitem__(c, __VA_ARGS__)
#define SETITEM(c, ...)((container *)c)->__setitem__(c, __VA_ARGS__)
