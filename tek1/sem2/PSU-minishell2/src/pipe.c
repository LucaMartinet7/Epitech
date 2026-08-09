/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-2-minishell2-luca.martinet
** File description:
** check_sussy
*/

#include "../include/my.h"

static int pipe_error(char *command, mysh_t *mysh)
{
    for (int i = 0; command[i] != '\0'; i++) {
        if (command[0] == '|') {
            my_printf("%s", "Invalid null command.\n");
            mysh->status = 1;
            return 84;
        } if (command[0] == '|' && command[1] == '\0') {
            my_printf("%s", "Invalid null command.\n");
            mysh->status = 1;
            return 84;
        } if (command[i] == '|' && command[i + 1] == '|') {
            my_printf("%s", "Invalid null command.\n");
            mysh->status = 1;
            return 84;
        } if (command[i] == '|' && command[i + 1] == '\0') {
            my_printf("%s", "Invalid null command.\n");
            mysh->status = 1;
            return 84;
        }
    }
    return 0;
}

static void run_pipe(void)
{
    return;
}

static void execute_pipe(mysh_t *mysh)
{
    char **args = my_str_word_array_sep(mysh->command, '|');
    int fdpipe[2];
    pipe_t *pipes = malloc(sizeof(pipe_t));

    if (pipe_error(mysh->command, mysh) == 84)
        return;
    mysh->pipes_cmd = args;
    pipes->save = 0;
    pipes->fd = fdpipe;
    for (int i = 0; args[i] != NULL; i++) {
        run_pipe();
    }
}

int check_pipe(mysh_t *mysh)
{
    int pipes = 0;
    for (int i = 0; mysh->command[i] != '\0'; i++) {
        if (mysh->command[i] == '|')
            pipes++;
        }
    if (pipes > 0)
        execute_pipe(mysh);
    return pipes;
}
