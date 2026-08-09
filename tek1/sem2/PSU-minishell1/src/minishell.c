/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-2-minishell2-luca.martinet
** File description:
** minishell
*/

#include "../include/my.h"

static void my_segfault(mysh_t *mysh)
{
    if (WIFSIGNALED(mysh->status)) {
        if (WTERMSIG(mysh->status) == 11) {
            my_putstr("Segmentation fault\n");
            mysh->status = 139;
        }
    }
}

void run_bin(mysh_t *mysh, char *path, char **args, char **env)
{
    pid_t pid = get_pid();
    if (pid == 0) {
        if (execve(path, args, env) == -1) {
            exit(2);
        }
        exit(2);
    } else {
        waitpid(pid, &mysh->status, 0);
        my_segfault(mysh);
    }
}

static int run_commands_check(mysh_t mysh, char *str, char **env)
{
    mysh.command = strtok(str, "\n");
    find_path(&(mysh), env);
    return 0;
}

int run_commands(char **env)
{
    size_t	buf_size = 0;
    mysh_t mysh;
    mysh.status = 0;
    char *str = NULL;
    while (1) {
        signal(SIGINT, check_signal);
        if (isatty(0) == 1)
            write(1, "$> ", 3);
        if (getline(&str, &buf_size, stdin) == -1)
            break;
        if (str[0] == '\n')
            continue;
        else
            run_commands_check(mysh, str, env);
    }
    if (isatty(0) == 1)
        my_printf("exit\n");
    return 0;
}
