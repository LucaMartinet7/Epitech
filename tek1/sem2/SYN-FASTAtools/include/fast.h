/*
** EPITECH PROJECT, 2023
** B-SYN-200-PAR-2-1-FASTAtools-luca.martinet
** File description:
** fast
*/

#ifndef FAST_H_
    #define FAST_H_

    #include <stdbool.h>

    typedef struct fast_s {
        char *buf;
        char **rest;
        char *str;
        char **seq;
        int status;
    } fast_t;
//check
    bool check_letter_cap_1(char c);
    bool check_letter_min_1(char c);
    bool check_letter_cap_2(char c);
    bool check_letter_min_2(char c);
//cases
    int case1(fast_t *fs);
    int case2(fast_t *fs);
    int case3(fast_t *fs);
//open file
    char **open_file(void);
    char *read_file(void);
//get_seq
    void get_seq(fast_t *fs);
    int nb_seq(char *str);
//get_rest
    char **get_rest(char *str);
//utils
    char *revstr(char *str);
    char capitalize(char c);
#endif /* !FAST_H_ */
