/*
** EPITECH PROJECT, 2022
** B-PSU-101-BDX-1-1-minishell1-leandre.godet
** File description:
** my_shell
*/

#include "my.h"
#include <stdio.h>
#include <signal.h>

void my_interrupt(int sig)
{
    if (sig == SIGINT)
        my_printf("\n%s%s%s ", "\33[1m\33[34m", "[>", "\33[0m");
}

int my_shell(char ***env)
{
    int status = 0;

    my_printf("%s%s%s ", "\33[1m\33[34m", "[>", "\33[0m");
    signal(SIGINT, my_interrupt);
    signal(SIGTSTP, SIG_IGN);
    status = loop_shell(env);
    if (status == 0)
        my_printf("exit\n");
    return status;
}
