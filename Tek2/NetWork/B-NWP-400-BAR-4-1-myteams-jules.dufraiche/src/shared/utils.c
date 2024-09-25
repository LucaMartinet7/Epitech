/*
** EPITECH PROJECT, 2024
** B-NWP-400-BAR-4-1-myteams-jules.dufraiche [WSL: Ubuntu]
** File description:
** utils
*/

#include "shared.h"

bool is_number(const char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] < '0' || str[i] > '9')
            return false;
    return true;
}
