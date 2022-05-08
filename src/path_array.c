/*
** EPITECH PROJECT, 2022
** Lib
** File description:
** str_to_word
*/

#include "my.h"

int count_paths(char const *str)
{
    int j = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ':' || str[i] == '=') {
            j += 1;
        }
    }
    return j + 1;
}

int path_letters(char const *str, int i)
{
    int j = 0;

    for (; str[i] != ':' && str[i] != '=' && str[i] != '\0'; i += 1)
        j += 1;
    return j;
}

char **put_path_in_array(char const *str, char **array, int i)
{
    int nb_letter = path_letters(str, i);
    int j = len_array(array);
    int k = 0;

    array[j] = malloc(sizeof(char) * nb_letter + 1);
    for (; str[i] != ':' && str[i] != '=' && str[i] != '\0'; k++) {
        array[j][k] = str[i];
        i++;
    }
    array[j][k] = '\0';
    return array;
}

int add_last_path(char const *str, char **array, int i)
{
    int j = len_array(array) - 1;

    i = i + my_strlen(array[j]);
    while (str[i] == ':' || str[i] == '=')
        i++;
    return i;
}

char **my_path_to_array(char *str)
{
    int nb_words = count_paths(str)  + 1;
    char **array = malloc(sizeof(char *) * nb_words);
    int i = 0;

    for (int j = 0; j < nb_words; j++) {
        array[j] = NULL;
    }
    while (str[i] != '\0') {
        array = put_path_in_array(str, array, i);
        i = add_last_path(str, array, i);
    }
    return array;
}
