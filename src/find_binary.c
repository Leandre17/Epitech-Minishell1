/*
** EPITECH PROJECT, 2022
** B-PSU-101-BDX-1-1-minishell1-leandre.godet
** File description:
** find_binary
*/

#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>
#include "my.h"

int is_same_string(char const *str1, char const *str2)
{
    int len_s1 = my_strlen(str1);
    int len_s2 = my_strlen(str2);

    if (len_s1 < len_s2 || len_s2 > len_s1)
        return 0;
    for (int i = 0; i < len_s1; i++) {
        if (str1[i] != str2[i])
            return 0;
    }
    return 1;
}

static int is_in_dir(const char *folder, const char *dir)
{
    DIR *directory = opendir(dir);
    struct dirent *fold = NULL;

    if (!directory)
        return 0;
    while ((fold = readdir(directory)) != NULL) {
        if (is_same_string(fold->d_name, folder)) {
            closedir(directory);
            return 1;
        }
    }
    closedir(directory);
    return 0;
}

char *search_in_path(char **line, char **env)
{
    char **path_array = NULL;
    char *dest = NULL;
    int pos = is_in_env("PATH", env);

    if (pos < 0)
        return NULL;
    path_array = my_path_to_array(env[pos]);
    for (int i = 1; path_array[i] != NULL; i++) {
        if (is_in_dir(line[0], path_array[i])) {
            dest = my_strcat("/", line[0]);
            return my_strcat(path_array[i], dest);
        }
    }
    return NULL;
}

int is_a_path(char *path)
{
    if (path == NULL)
        return 0;
    for (int i = 0; path[i] != '\0'; i += 1) {
        if (path[i] == '/')
            return 1;
    }
    return 0;
}

char *find_command(char **line, char **env)
{
    char *command = search_in_path(line, env);

    if (is_a_path(line[0]))
        return my_strcat("./", line[0]);
    return command;
}
