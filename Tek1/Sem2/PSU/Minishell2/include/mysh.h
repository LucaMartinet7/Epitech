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
    #include <stdbool.h>
    #define EXIT_FAILURE 1
    #define X_OK 1

typedef struct mysh_s {
    char *command;
    char *commandpath;
    char **args;
    char **env;
    char **struct_env;
    int status;
    char **pipes_cmd;
    bool pipe;
} mysh_t;

typedef struct pipe_s {
    int *fd;
    int save;
} pipe_t;

//array.c
    char **get_path_array(char *path_env);
//builtin.c
    int check_builtins(mysh_t *mysh);
    void print_env(mysh_t *mysh);
//builtins_cd.c
    int do_cd(mysh_t *mysh);
    char *get_oldpwd(char **env);
//builtin_env.c
    void do_setenv(mysh_t *mysh);
    char **cpy_env(char **env);
//check.c
    void check_signal(int signal);
    void handle_segfault(int signal);
    void check_access(mysh_t *mysh, char **args, char *path);
    pid_t get_pid(void);
//minishell.c
    int run_commands(mysh_t *mysh, char **env);
    void run_bin(mysh_t *mysh, char *path);
//path.c
    void find_path(mysh_t *mysh);
    char *put_path(char *command, char **env);
    char *get_path_env(char **env);
//pipes
    int check_pipe(mysh_t *mysh);

#endif /* !MYSH_H_ */
