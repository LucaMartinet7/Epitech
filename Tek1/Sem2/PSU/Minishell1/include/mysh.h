/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-2-minishell2-luca.martinet
** File description:
** mysh
*/

#ifndef MYSH_H_
    #define MYSH_H_
    #include <unistd.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    #include <stdarg.h>
    #include <sys/types.h>
    #include <sys/wait.h>
    #include <sys/stat.h>
    #include <dirent.h>
    #include <errno.h>
    #include <signal.h>
    #include <fcntl.h>

typedef struct mysh_s {
    char *command;
    char *commandpath;
    char **args;
    char **env;
    int status;
} mysh_t;

//array.c
    char **get_path_array(char *path_env);
//builtin.c
    int check_builtins(mysh_t *mysh, char **args, char **env);
    void print_env(char **array);
//builtins_cd.c
    int do_cd(char **args, char **env);
//builtin_env.c
    char **do_setenv(char **args, char **new_env);
//check.c
    void check_signal(int signal);
    pid_t get_pid(void);
//minishell.c
    int run_commands(char **env);
    void run_bin(mysh_t *mysh, char *path, char **args, char **env);
//path.c
    void find_path(mysh_t *mysh, char **env);
    char *put_path(char *command, char **env);
    char *get_path_env(char **env);

#endif /* !MYSH_H_ */
