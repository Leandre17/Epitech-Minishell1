/*
** EPITECH PROJECT, 2022
** B-PSU-101-BDX-1-1-minishell1-leandre.godet
** File description:
** shell_loop
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int loop_shell(char ***env)
{
    char *line = NULL;
    char **cmd = NULL;
    int status = 0;
    size_t len = 0;
    int read;

    while ((read = getline(&line, &len, stdin)) != -1) {
        cmd = my_str_to_word_array(line);
        if (cmd[0][0] != '\0') {
            status = handle_command(cmd, env);
            free_tab(cmd);
        }
        my_printf("%s%s%s ", "\33[1m\33[34m", "[>", "\33[0m");
    }
    free(line);
    return status;
}
