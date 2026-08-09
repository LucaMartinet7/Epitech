##
## EPITECH PROJECT, 2023
## B-SYN-200-PAR-2-1-automakefile-luca.martinet
## File description:
## skip-synthesis
##

#!usr/bin/sh

gawk '{print $3, "\t", $9}' | grep \ $1
