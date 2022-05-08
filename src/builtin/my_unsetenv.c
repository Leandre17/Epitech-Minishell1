/*
** EPITECH PROJECT, 2022
** B-PSU-101-BDX-1-1-minishell1-leandre.godet
** File description:
** my_unsetenv
*/

#include "my.h"

int is_in_str(char *str, char *to_check)
{
    int len_to_check = my_strlen(to_check);
    int i = 0;

    while (i < len_to_check) {
        if (to_check[i] != str[i]) {
            return 0;
        }
        i += 1;
    }
    if (str[i] == '=')
        return 1;
    return 0;
}

int is_in_env(char *name, char **env)
{
    int i = 0;

    if (name == NULL || env == NULL)
        return -2;
    while (env[i] != NULL) {
        if (my_strcmp(env[i], name) == 0) {
            return i;
        }
        i += 1;
    }
    return -1;
}

void move_by_one(char ***env, int pos)
{
    if (env == NULL || env[0] == NULL)
        return;
    while (env[0][pos + 1] != NULL) {
        env[0][pos] = env[0][pos + 1];
        pos += 1;
    }
    env[0][pos] = env[0][pos + 1];
}

int my_unsetenv(int status, char **cmd, char ***env)
{
    int pos = 0;

    if (!env || !cmd || !env[0])
        return -1;
    else if (!cmd[1]) {
        my_printf("unsetenv: Too few arguments.\n");
        return 1;
    }
    pos = is_in_env(cmd[1], env[0]);
    if (pos == -1)
        return 0;
    move_by_one(env, pos);
    status = 0;
    return status;
}
