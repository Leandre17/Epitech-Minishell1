/*
** EPITECH PROJECT, 2022
** B-PSU-101-BDX-1-1-minishell1-leandre.godet
** File description:
** my_cd
*/

#include <unistd.h>
#include <string.h>
#include <errno.h>

#include "my.h"

int change_pwd(char **pwd_path, char ***env)
{
    char *cmd[] = {"setenv", "OLDPWD", NULL, NULL};
    char *buf = NULL;

    if (pwd_path == NULL || pwd_path[1] == NULL)
        return 1;
    cmd[2] = pwd_path[1];
    my_setenv(0, cmd, env);
    cmd[1] = "PWD";
    cmd[2] = getcwd(buf, 0);
    my_setenv(0, cmd, env);
    free_tab(pwd_path);
    free(cmd[2]);
    return 0;
}

int find_pwd(char *path, char ***env)
{
    int pos = 0;
    char **pwd_path = NULL;

    if (path == NULL || env == NULL || env[0] == NULL)
        return 1;
    pos = is_in_env("PWD", env[0]);
    if (pos < 0)
        return 1;
    pwd_path = my_path_to_array(env[0][pos]);
    return change_pwd(pwd_path, env);
}

int change_directory(char *path, char ***env)
{
    int err = 0;

    if (path == NULL)
        return 1;
    err = chdir(path);
    if (err == -1) {
        my_printf("%s: %s.\n", path, strerror(errno));
        return 1;
    }
    return find_pwd(path, env);
}

int replace_home_path(char *home_path, char **cmd, char ***env)
{
    char *new_path = NULL;

    if (cmd[1][1] == '\0')
        return change_directory(home_path, env);
    new_path = my_move_char_by_one(cmd[1], 0);
    new_path = my_strcat(home_path, new_path);
    return change_directory(new_path, env);
}
