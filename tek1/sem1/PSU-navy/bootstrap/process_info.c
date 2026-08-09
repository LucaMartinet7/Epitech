/*
** EPITECH PROJECT, 2023
** B-PSU-100-PAR-1-2-navy-noe.kurata
** File description:
** process_info
*/

#include <unistd.h>
#include <stdio.h>

int main(void)
{
    int pid = getpid();
    int ppid = getppid();
    int pgid = getpgrp();
    printf("PID = %d\n", pid);
    printf("PPID = %d\n", ppid);
    printf("PGID = %d\n", pgid);
}