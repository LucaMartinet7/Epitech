/*
** EPITECH PROJECT, 2023
** temp
** File description:
** pal
*/

#ifndef PAL_H_
    #define PAL_H_
    #include <stdbool.h>
    typedef struct pal_s {
        int nb;
        int nb_cpy;
        int base;
        int imax;
        int imin;
        int counter;
        int status;
        int solution;
        int n;
        int p;
        int check;
        int nb_p;
        int nb_p_cpy;
    } pal_t;

    int validation(pal_t *pal, int ac, char **av);
    int v_nb(pal_t *pal, char *str);
    bool is_palindrome(pal_t *pal);
    int convert_base(int nbr, int base);
    int do_addition(pal_t *pal);
    int revert_base(int nbr, int base);
    int chose_palindrome(pal_t *pal);
    bool is_palindrome_2(int nbr);
    int palindrome(pal_t *pal);
    int revert_p(int num);

#endif /* !PAL_H_ */
