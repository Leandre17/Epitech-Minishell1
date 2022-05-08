/*
** EPITECH PROJECT, 2022
** B-PSU-101-BDX-1-1-minishell1-leandre.godet
** File description:
** command
*/

#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include "my.h"

int check_segfault(int status)
{
    if (!WIFSIGNALED(status))
        return WEXITSTATUS(status);
    my_printf("%s\n", strsignal(WTERMSIG(status)));
    return (WTERMSIG(status));
}

int exec_cmd(char **line, char **env)
{
    char *cmd = find_command(line, env);
    int pid = 0;
    int status = 0;

    if (cmd == NULL) {
        my_printf("%s: Command not found.\n", line[0]);
        return 0;
    }
    pid = fork();
    if (pid == 0) {
        execve(cmd, line, env);
        my_printf("%s: %s.\n", line[0], strerror(errno));
        my_xit(status, NULL, NULL);
    } else
        waitpid(pid, &status, 0);
    return check_segfault(status);
}

int handle_command(char **line, char ***env)
{
    char *function[] = {"env", "exit", "cd", "setenv", "unsetenv", 0};
    int (*builtin[])(int, char **, char ***) = {my_env, my_xit, my_cd,
    my_setenv, my_unsetenv, 0};
    int j = 0;

    while (!is_same_string(line[0], function[j])) {
        if (j == 4)
            return exec_cmd(line, env[0]);
        j += 1;
    }
    return builtin[j](0, line, env);
}
