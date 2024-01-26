/*
** EPITECH PROJECT, 2023
** B-SYN-200-PAR-2-1-sbmlparser-luca.martinet
** File description:
** helper
*/
#include <stdio.h>
#include "../include/sbml.h"

void tiret_h(void)
{
    printf("USAGE\n");
    printf("\t./SBMLparser SBMLfile [-i ID [-e]] [-json]\n");
    printf("DESCRIPTION\n");
    printf("\tSBMLfile \tSBML file\n");
    printf("\t-i ID \tid of the compartment, reaction or");
    printf("product to be extracted\n");
    printf("\t\t(ignored if uncorrect)\n");
    printf("\t-e \tprint the equation if a reaction ID is given as argument\n");
    printf("\t\t(ignored otherwise)\n");
    printf("\t-json \ttransform the file into a JSON file\n");
}
