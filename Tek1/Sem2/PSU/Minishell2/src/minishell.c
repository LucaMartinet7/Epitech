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
            my_putstr("Segmentation fault (core dumped)\n");
            mysh->status = 139;
        }
    }
}

void exceve_check(mysh_t *mysh, char *name, int err)
{
    if (err == 2) {
        my_printf("%s: Command not found.\n", name);
        mysh->status = 1;
    } else {
        my_printf("%s: ", name);
        my_putstr(strerror(err));
        my_putstr(".\n");
        mysh->status = 1;
    }
}

void run_bin(mysh_t *mysh, char *path)
{
    pid_t pid = get_pid();
    if (pid == 0) {
        if (execve(path, mysh->args, mysh->env) == -1) {
            exceve_check(mysh, mysh->args[0], errno);
            exit(1);
        }
    }
    wait(&mysh->status);
    my_segfault(mysh);
}

static int run_commands_check(mysh_t *mysh)
{
    mysh->command = strtok(mysh->command, "\n");
    find_path(mysh);
    return 0;
}

int run_commands(mysh_t *mysh, char **env)
{
    size_t	buf_size = 0;
    mysh->status = 0;
    mysh->command = NULL;
    mysh->env = cpy_env(env);
    while (1) {
        signal(SIGINT, check_signal);
        if (isatty(0) == 1)
            write(1, "$> ", 3);
        if (getline(&mysh->command, &buf_size, stdin) == -1)
            break;
        if (mysh->command[0] == '\n')
            continue;
        else
            run_commands_check(mysh);
    }
    if (isatty(0) == 1)
        my_printf("exit\n");
    return 0;
}
