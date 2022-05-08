/*
** EPITECH PROJECT, 2022
** B-PSU-101-BDX-1-1-minishell1-leandre.godet
** File description:
** env
*/

#include "my.h"

int my_env(int status, char **cmd, char ***env)
{
    if (env == NULL || env[0] == NULL || !cmd)
        return 0;
    for (int i = 0; env[0][i]; i++) {
        my_printf("%s\n", env[0][i]);
    }
    status = 0;
    return status;
}
