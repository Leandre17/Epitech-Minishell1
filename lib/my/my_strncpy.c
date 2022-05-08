/*
** EPITECH PROJECT, 2021
** strncpy
** File description:
** copy n char from a string
*/

int my_strlen1(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i = i + 1;
    }
    return (i);
}

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while (i != n) {
        if (i > my_strlen1(src)) {
            dest[i] = '\0';
        } else {
            dest[i] = src[i];
        }
        i = i + 1;
    }
    return (dest);
}
