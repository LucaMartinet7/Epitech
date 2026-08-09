/*
** EPITECH PROJECT, 2022
** B-CPE-110-PAR-1-2-pushswap-luca.martinet
** File description:
** my.h
*/

#include <stdio.h>
#include <stdlib.h>

#ifndef STRUCT_H_
    #define STRUCT_H_

    int my_atoi(char *str);

    typedef struct node{
        int nb;
        struct node *next;
    } node_t;

#endif
