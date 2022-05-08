/*
** EPITECH PROJECT, 2022
** B-PSU-101-BDX-1-1-minishell1-leandre.godet
** File description:
** env_copy
*/
#include "my.h"

char **my_env_copy(char const **env)
{
    int size = 0;
    char **envc = NULL;

    while (env[size] != NULL)
        size += 1;
    envc = malloc(sizeof(char *) * (size + 1));
    for (int index = 0; index < size; index++) {
        envc[index] = malloc(sizeof(char) * my_strlen(env[index]) + 1);
        envc[index] = my_strcpy(envc[index], env[index]);
    }
    envc[size] = NULL;
    return envc;
}
