/*
** EPITECH PROJECT, 2023
** B-SYN-200-PAR-2-1-FASTAtools-luca.martinet
** File description:
** check
*/

#include "../include/fast.h"

bool check_letter_min_1(char c)
{
    return (c == 'a' || c == 't' || c == 'g'
    || c == 'c' || c == 'n') ? true : false;
}

bool check_letter_cap_1(char c)
{
    return (c == 'A' || c == 'T' || c == 'G'
        || c == 'C' || c == 'N') ? true : false;
}

bool check_letter_min_2(char c)
{
    return (c == 'a' || c == 'g'
        || c == 'c' || c == 'n') ? true : false;
}

bool check_letter_cap_2(char c)
{
    return (c == 'A' || c == 'G'
        || c == 'C' || c == 'N') ? true : false;
}
