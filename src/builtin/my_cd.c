/*
** EPITECH PROJECT, 2022
** B-PSU-101-BDX-1-1-minishell1-leandre.godet
** File description:
** my_cd
*/

#include <unistd.h>
#include <errno.h>
#include "my.h"

int find_oldpwd(char ***env)
{
    char **pwd_path = NULL;
    int pos = is_in_env("OLDPWD", env[0]);

    if (pos < 0) {
        my_printf("cd: No oldpwd directory.\n");
        return 1;
    }
    pwd_path = my_path_to_array(env[0][pos]);
    return change_directory(pwd_path[1], env);
}

char *find_home(char ***env)
{
    char **home_path = NULL;
    int pos = 0;

    pos = is_in_env("HOME", env[0]);
    if (pos < 0) {
        my_printf("cd: No home directory.\n");
        return NULL;
    }
    home_path = my_path_to_array(env[0][pos]);
    free(home_path[0]);
    return home_path[1];
}

int special_directory(char **cmd, char ***env)
{
    char *home_path = NULL;

    if (cmd == NULL || env == NULL || env[0] == NULL)
        return 1;
    else if (cmd[1] != NULL && cmd[1][0] == '-' && cmd[1][1] != '-')
        return find_oldpwd(env);
    home_path = find_home(env);
    if (home_path == NULL)
        return 1;
    else if (cmd[1] == NULL || cmd[1][1] == '-')
        return change_directory(home_path, env);
    else
        return replace_home_path(home_path, cmd, env);
}

int my_cd(int status, char **cmd, char ***env)
{
    if (cmd == NULL || env == NULL || env[0] == NULL)
        return 1;
    else if (cmd[1] == NULL || cmd[1][0] == '~' || cmd[1][0] == '-')
        return special_directory(cmd, env);
    else
        return change_directory(cmd[1], env);
    status = 0;
    return status;
}
