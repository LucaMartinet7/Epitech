/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-2-minishell2-luca.martinet
** File description:
** my_strncmp
*/

#include "../../include/my.h"

int my_strncmp(char const *s1 , char const *s2, int nb)
{
    for (int i = 0; i < nb; i++) {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
    }
    return 0;
}
