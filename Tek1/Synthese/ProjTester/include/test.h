/*
** EPITECH PROJECT, 2023
** B-SYN-200-PAR-2-1-projtester-luca.martinet
** File description:
** test
*/

#ifndef TEST_H_
    #define TEST_H_
    #include <stdbool.h>
    #include <dirent.h>

    typedef struct test_s {
        int status;
        char **title;
        char **path;
    } test_t;

//parse
    int parse(test_t *ts, int ac, char **av);
//help
    int tiret_h(void);
//str w array
    char **str_warray(const char *str);
    char **get_path_array(char *path_env);
//opt 1
    void search_trd(test_t *ts, char *str);
//free
    void free_func(char **arr);
    void free_dir(struct dirent **dir, int x);
//check bft
char *check_path(test_t *ts, char *str);
int opt_echo(char *str, char *cmd);

#endif /* !TEST_H_ */
