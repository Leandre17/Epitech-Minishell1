/*
** EPITECH PROJECT, 2022
** B-PSU-101-BDX-1-1-minishell1-leandre.godet
** File description:
** check_stdin
*/

#include "my.h"
#include <fcntl.h>
#include <unistd.h>

int check_stdin(char ***env)
{
    char buf[1];
    int fd = open("/dev/stdin", O_NONBLOCK);
    int status = 0;
    int s = read(fd, buf, 1);

    if (s < 1) {
        status = my_shell(env);
    } else {
        buf[s] = '\0';
        status = echo_shell(env, buf);
    }
    close(fd);
    return status;
}
