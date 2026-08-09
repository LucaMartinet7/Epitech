/*
** EPITECH PROJECT, 2022
** rush3
** File description:
** rush 3
*/

#include"my.h"
#include<unistd.h>

int main(void)
{
    int BUFF_SIZE = 32000;
    char buff[BUFF_SIZE + 1];
    int offset = 0;
    int len ;
    while ((len = read(0, buff + offset , BUFF_SIZE - offset)) > 0) {
        offset = offset + len ;
    }
    buff[offset] = '\0';
    if (len < 0)
        return (84) ;
    rush3(buff);
    my_putchar('\n');
    return (0);
}
