/*
** EPITECH PROJECT, 2022
** B-PSU-101-BDX-1-1-minishell1-leandre.godet
** File description:
** shell_echo
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "my.h"

int echo_shell(char ***env, char *buf)
{
    char **cmd = NULL;
    int status = 0;
    size_t len = 0;
    char *line = NULL;
    int read = getline(&line, &len, stdin);

    line = my_strcat(buf, line);
    while (read != -1) {
        cmd = my_str_to_word_array(line);
        if (cmd[0][0] != '\0') {
            status = handle_command(cmd, env);
            free_tab(cmd);
        }
        read = getline(&line, &len, stdin);
    }
    free_tab(env[0]);
    return status;
}
