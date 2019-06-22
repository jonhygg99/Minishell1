/*
** EPITECH PROJECT, 2018
** my_strcat
** File description:
** concatenate two strings
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
    int i;
    int j;
    char *str = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 1));

    for (i = 0; dest[i] != '\0'; i++)
        str[i] = dest[i];
    for (j = 0; src[j] != '\0'; j++)
        str[i + j] = src[j];
    str[i + j] = '\0';
    return (str);
}
