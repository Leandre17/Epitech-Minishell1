/*
** EPITECH PROJECT, 2022
** B-PSU-101-BDX-1-1-bsminishell1-leandre.godet
** File description:
** main
*/
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include "my.h"

int main(int argc, char const **argv, char const **env)
{
    int status = 0;
    char **envc = NULL;

    if (env == NULL || env[0] == NULL || !argv)
        return 0;
    if (argc != 1)
        return 1;
    envc = my_env_copy(env);
    status = check_stdin(&envc);
    return status;
}
