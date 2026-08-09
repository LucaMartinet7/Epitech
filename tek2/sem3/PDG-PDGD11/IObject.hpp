/*
** EPITECH PROJECT, 2024
** Paradigms Seminar
** File description:
** Day 11
*/

#pragma once

class IObject
{
public:
    virtual ~IObject() = default;

    virtual void touch() = 0;
};
