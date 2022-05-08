/*
** EPITECH PROJECT, 2022
** Lib
** File description:
** str_to_word
*/

#include "my.h"

char **put_word_in_array(char const *str, char **array, int i)
{
    int nb_letter = nb_letter = count_letters(str, i) + 1;
    int j = len_array(array);
    int k = 0;

    array[j] = malloc(sizeof(char) * nb_letter);
    for (; str[i] != ' '; k++) {
        array[j][k] = str[i];
        i++;
    }
    array[j][k] = '\0';
    return array;
}

int add_last_arr(char const *str, char **array, int i)
{
    int j = len_array(array) - 1;

    i = i + my_strlen(array[j]);
    while (str[i] == ' ')
        i++;
    return i;
}

char *replace_new_line(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n' || str[i] == '\r' || str[i] == '\t') {
            str[i] = ' ';
        }
    }
    return str;
}

char **my_str_to_word_array(char *str)
{
    int nb_words = count_words(str) + 1;
    char **array = malloc(sizeof(char *) * nb_words);
    int i = 0;

    for (int j = 0; j < nb_words; j++) {
        array[j] = NULL;
    }
    while (str[i] == ' ' || str[i] == '\t')
        i++;
    str = replace_new_line(str);
    while (str[i] != '\0') {
        array = put_word_in_array(str, array, i);
        i = add_last_arr(str, array, i);
    }
    return array;
}
