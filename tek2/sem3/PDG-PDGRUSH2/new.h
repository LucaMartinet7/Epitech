/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 01
*/

#pragma once

#include <stdarg.h>
#include "object.h"

object *new(const Class *class, ...);
object *va_new(const Class *class, va_list* ap);
void delete(object *ptr);
