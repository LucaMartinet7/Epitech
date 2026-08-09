/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 05
*/

#pragma once

#include "object.h"
#include "raise.h"

typedef struct Iterator_s iterator;

typedef void (*incr_t)(iterator *this);
typedef object *(*getval_t)(iterator *this);
typedef void (*setval_t)(iterator *this, ...);

struct Iterator_s {
    Class base;
    incr_t __incr__;
    getval_t __getval__;
    setval_t __setval__;
};

#define INCR(it) ((iterator *)it)->__incr__(it)
#define GETVAL(it) ((iterator *)it)->__getval__(it)
#define SETVAL(it, ...) ((iterator *)it)->__setval__(it, __VA_ARGS__)
