/*
** EPITECH PROJECT, 2022
** B-PSU-101-BDX-1-1-minishell1-leandre.godet
** File description:
** my_setenv
*/

#include "my.h"

int check_name(char const *name)
{
    if (name[0] >= '0' && name[0] <= '9') {
        my_printf("setenv: Variable name must begin with a letter.\n");
        return 1;
    }
    for (int i = 0; i < my_strlen(name); i++) {
        if (!my_char_isalphanum(name[i]) && name[i] != '_') {
            my_printf("setenv: Variable name must ");
            my_printf("contain alphanumeric characters.\n");
            return 1;
        }
    }
    return 0;
}

int add_to_env(char **cmd, char ***env)
{
    int i = 0;

    if (cmd == NULL || env == NULL || cmd[1] == NULL || env[0] == NULL)
        return -1;
    else if (len_array(cmd) > 3) {
        my_printf("setenv: Too many arguments.\n");
        return 1;
    }
    while (env[0][i] != NULL)
        i += 1;
    if (check_name(cmd[1]))
        return 1;
    env[0][i] = my_strcat(cmd[1], "=");
    if (cmd[2] != NULL)
        env[0][i] = my_strcat(env[0][i], cmd[2]);
    env[0][i + 1] = NULL;
    return 0;
}

int modify_env(char **cmd, char ***env)
{
    if (cmd == NULL || cmd[1] == NULL || cmd[2] == NULL)
        return 1;
    else if (cmd[3] != NULL) {
        my_printf("setenv: Too many arguments.\n");
        return 1;
    }
    my_unsetenv(0, cmd, env);
    my_setenv(0, cmd, env);
    return 0;
}

int my_setenv(int status, char **cmd, char ***env)
{
    int pos = 0;

    if (cmd == NULL || env == NULL)
        return 1;
    else if (cmd[1] == NULL)
        return my_env(0, NULL, env);
    pos = is_in_env(cmd[1], env[0]);
    status = 0;
    if (pos == -1)
        return add_to_env(cmd, env);
    else
        return modify_env(cmd, env);
    return status;
}
