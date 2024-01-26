/*
** EPITECH PROJECT, 2023
** B-SYN-200-PAR-2-1-sbmlparser-luca.martinet
** File description:
** sbml
*/

#ifndef SBML_H_
    #define SBML_H_
    typedef struct sbml_s {
        char **tab;
        char **categories;
        char *buffer;
        char *str;
    } sbml_t;

    void tiret_h(void);
    int sbml(sbml_t *sb, int ac, char **av);
    char **str_word_arr(const char *str);
    int check_file(char *str);
    char *open_file(char **av);
    int my_strlen(char *str);
    void find_all_categories(sbml_t *sb);

#endif /* !SBML_H_ */
