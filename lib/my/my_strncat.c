/*
** EPITECH PROJECT, 2021
** strcat
** File description:
** concattrnates
*/

char *my_strncat(char *dest, char const *src, int n)
{
    int i = 0;
    int j = 0;

    while (dest[i] != '\0')
        i = i + 1;
    while (j != n) {
        dest[i] = src[j];
        i = i + 1;
        j = j + 1;
    }
    return (dest);
}
