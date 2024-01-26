/*
** EPITECH PROJECT, 2023
** bruh moment
** File description:
** bruh moment
*/

#include "my.h"

void check2(total_val)
{
    if (total_val % 10 == 0)
        write(1, "valid\n", 6);
    else
        write(1, "invalid\n", 8);
}

int check1(int temp)
{
    if (temp > 9) {
        temp = temp - 9;
    }
    return temp;
}

int main(int ac, char **av)
{
    int total_val = 0;
    char *str = av[1];
    int len = my_strlen(str);
    int temp = 0;
    int j = 0;
    for (int i = len - 2; i >= 0; i--) {
        temp = str[i] - '0';
        if (i % 2 != 0) {
            temp = temp * 2;
            str[i] = check1(temp);
        }
        else {
            str[i] = str[i] - '0';
        }
        total_val =  + str[i] + total_val;
    }
    int first_num = str[len - 1] - '0';
    total_val = total_val + first_num;
    check2(total_val);
    return 0;
}
