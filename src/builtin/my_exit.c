/*
** EPITECH PROJECT, 2022
** B-PSU-101-BDX-1-1-minishell1-leandre.godet
** File description:
** my_exit
*/

#include "my.h"
#include <stdlib.h>

int my_xit(int status, char **cmd, char ***env)
{
    exit(status);
    free(cmd);
    free(env);
    return 0;
}
