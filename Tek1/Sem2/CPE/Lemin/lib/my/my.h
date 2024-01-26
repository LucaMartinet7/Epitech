/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** my includes
*/

#ifndef MY_H_
    #define MY_H_

//library
unsigned int my_put_unsigned_nbr(unsigned int nb);
unsigned int my_decimal_to_octal(unsigned int decimalnum);
unsigned int my_put_binary(unsigned int decimalnum);

void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strcat(char *dest, char const *src);
char *my_revstr(char *str);
char *my_strncat(char *dest, char const *src, int nb);
char *my_strdup(const char *str);

#endif /* MY_H_ */
