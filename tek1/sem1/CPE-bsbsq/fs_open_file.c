/*
** EPITECH PROJECT, 2022
** B-CPE-110-PAR-1-2-bsbsq-luca.martinet
** File description:
** fs_open_file.c
*/
#include"my_printf/include/my_printf.h"
#include<stdio.h>
#include<fcntl.h>
#include<errno.h>

int fs_open_file(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    if (fd ==-1) {
        printf("%s\n", "FAILURE");
    } else
        printf("%s\n", "SUCCESS");
    close(fd);
}

int main()
{
    fs_open_file("map1.txt");
}