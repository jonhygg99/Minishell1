/*
** EPITECH PROJECT, 2019
** point_2_pointer
** File description:
** convert char * to char **
*/

#include "../my.h"

int remove_spaces(char *str, int i)
{
    while (str[i++] == ' ');
    return (i);
}

int remove_words(char *str, int i)
{
    while (str[i])
        if (str[i++] != ' ')
            break;
    return (i);
}

char **malloc_2_pointer(char *str)
{
    int i;
    int j = 0;
    int k = 0;
    int space = 1;
    char **pointer;

    for (i = 0; i <= my_strlen(str); i++) {
        if (str[i] == ' ') {
            i = remove_spaces(str, i);
        } else {
            space++;
            i = remove_words(str, i);
        }
    }
    pointer = malloc(sizeof(char *) * (space + 1));
    for (i = 0; i <= space; i++)
        pointer[j++] = malloc(sizeof(char) * (my_strlen(str)));
    return (pointer);
}

char **point_2_pointer(char *str)
{
    char **pointer;
    char *word = malloc(sizeof(char) * my_strlen(str) + 1);
    int j = 0;
    int k = 0;

    pointer = malloc_2_pointer(str);
    for (int i = 0; i <= my_strlen(str); i++) {
        if (str[i] == ' ') {
            pointer[k][j] = '\0';
            k++;
            j = 0;
        } else
            pointer[k][j++] = str[i];
    }
    pointer[++k] = NULL;
    return (pointer);
}
