/*
** EPITECH PROJECT, 2021
** test_projet
** File description:
** test_projet
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "minishell.h"
#include "my.h"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(test_error, my_env, .init=redirect_all_stdout)
{
    char **env = {NULL};
    char **env1 = malloc(sizeof(char *) * 4);
    char *cmd[] = {"hey", NULL};

    env1[0] = "111";
    env1[1] = "999";
    env1[2] = NULL;


    cr_assert_eq(my_env(0, NULL, NULL), 0);
    cr_assert_eq(my_env(0, NULL, &env), 0);
    my_env(0, cmd, &env1);
    cr_assert_stdout_eq_str("111\n999\n");
    free(env1);
}

Test(test_error, setenv_unsetenv)
{
    char **env1 = malloc(sizeof(char *) * 4);
    char *cmd[] ={"setenv", "a111", "999", NULL};
    char *cmd1[] ={"setenv", "a111", "999", NULL};
    char *cmd2[] ={"unsetenv", "a1111", NULL};
    char *cmd3[] ={"setenv", "a111", "999", NULL};
    char *cmd4[] ={"unsetenv", NULL};
    char *cmd5[] ={"setenv", "a111", "999", "1", NULL};
    char **env = {NULL};

    env1[0] = "a111=111";
    env1[1] = "a999=999";
    env1[2] = NULL;

    cr_assert_eq(my_unsetenv(0, cmd2, &env1), 0);
    cr_assert_eq(my_unsetenv(0, cmd4, &env1), 1);
    cr_assert_eq(my_unsetenv(0, cmd5, &env), -1);
    cr_assert_eq(my_setenv(0, cmd, &env1), 0);
    cr_assert_eq(my_setenv(0, cmd1, &env1), 0);
    cr_assert_eq(my_setenv(0, cmd2, &env1), 0);
    cr_assert_eq(my_setenv(0, cmd3, &env1), 0);
    cr_assert_eq(my_setenv(0, cmd4, &env1), 0);
    cr_assert_eq(my_setenv(0, cmd5, &env1), 1);
    cr_assert_eq(my_setenv(0, NULL, &env1), 1);
    cr_assert_eq(add_to_env(NULL, NULL), -1);
    cr_assert_eq(modify_env(0, NULL), 1);
    cr_assert_eq(is_in_env(NULL, NULL), -2);
    move_by_one(&env, 0);
    free(env1);
}

Test(test_cd, my_cd)
{
    char **env1 = malloc(sizeof(char *) * 3);
    char **env2 = malloc(sizeof(char *) * 3);
    char *cmd[] ={"cd", "~", NULL};
    char *cmd1[] ={"cd", "/", NULL};
    char *cmd2[] ={NULL};
    char *cmd3[] ={"cd", "iknbutimnothere", NULL};
    char *cmd4[] ={"cd", "-", NULL};
    char **env = {NULL};

    env2[0] = "PWD=/bin";
    env2[1] = "OLDPWD=/";
    env2[2] = NULL;
    env1[0] = "MMM=/bin";
    env1[1] = "HOME=/home/gleandre";
    env1[2] = NULL;

    cr_assert_eq(my_cd(0, cmd, &env1), 1);
    cr_assert_eq(my_cd(0, cmd, &env), 1);
    cr_assert_eq(my_cd(0, cmd, &env2), 1);
    cr_assert_eq(my_cd(0, cmd1, &env2), 0);
    cr_assert_eq(my_cd(0, cmd1, &env1), 1);
    cr_assert_eq(my_cd(0, cmd2, &env1), 1);
    cr_assert_eq(my_cd(0, cmd3, &env1), 1);
    cr_assert_eq(special_directory(cmd4, &env1), 1);
    cr_assert_eq(find_pwd(NULL, &env), 1);
    cr_assert_eq(special_directory(NULL, &env), 1);
    cr_assert_eq(change_directory(NULL, &env), 1);
    cr_assert_eq(change_pwd(NULL, &env), 1);
    cr_assert_eq(find_oldpwd(&env1), 1);
    cr_assert_eq(find_oldpwd(&env2), 0);
    free(env1);
    free(env2);
}
