/*
** EPITECH PROJECT, 2022
** hieyhjh
** File description:
** hjudfhgkj
*/

#ifndef PRINTF_H_
    #define PRINTF_H_
    #include <unistd.h>
    #include <stdlib.h>
    #include <fcntl.h>
    #include <stdio.h>
    #include <sys/stat.h>
    #include <stdarg.h>

void my_putchar(char c);
int show_number(int nb);
int show_string(char const *str);
char *reverse_string(char *str);
int to_number(char const *str);
int is_prime_number(int nb);
char *my_strcpy(char *dest, char const *src);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strlength(const char *str);
char *my_strcat(char *dest, char const *src);
void display_limits(int nb);
char *openfile(char *av);
int my_printf(const char *restrict forma, ...);
int int_2_bin(int nb);
void int_2_oct(int nb);
int uns_dec(unsigned int nb);
char *hex_maj(int nb);
char *hex_min(int nb);
int power(int nb);
int my_compute_power_rec (int nb , int p);
int backn(char *str);
char **my_str2linearray(char *str, int n);
char *my_strncpy(char *dest, char const *src, int n);
char** my_str2wordarray(char* string);


#endif
