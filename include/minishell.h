/*
** EPITECH PROJECT, 2022
** B-PSU-101-BDX-1-1-minishell1-leandre.godet
** File description:
** minishell
*/

#ifndef MINISHELL_H_
    #define MINISHELL_H_

int my_xit(int status, char **cmd, char ***env);

int my_unsetenv(int status, char **cmd, char ***env);
int my_setenv(int status, char **cmd, char ***env);
int my_env(int status, char **cmd, char ***env);
int add_to_env(char **cmd, char ***env);
int modify_env(char **cmd, char ***env);
void move_by_one(char ***env, int pos);
int is_in_env(char *name, char **env);

int replace_home_path(char *home_path, char **cmd, char ***env);
int my_cd(int status, char **cmd, char ***env);
int special_directory(char **cmd, char ***env);
int change_directory(char *path, char ***env);
int change_pwd(char **pwd_path, char ***env);
int find_pwd(char *path, char ***env);
int is_in_env(char *name, char **env);
int change_to_home(char ***env);
int find_oldpwd(char ***env);
char *find_home(char ***env);


int is_same_string(char const *str1, char const *str2);
int handle_command(char **line, char ***env);
char *find_command(char **line, char **env);
char **my_path_to_array(char *str);


int echo_shell(char ***env, char *line);
int check_stdin(char ***env);
int loop_shell(char ***env);
int my_shell(char ***env);

#endif /* !MINISHELL_H_ */
