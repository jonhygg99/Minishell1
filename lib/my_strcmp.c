/*
** EPITECH PROJECT, 2018
** my_strcmp
** File description:
** compare strs and return the substract in ascii
*/

#include "../my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i;
    int j;
    int letter;

    j = 0;
    letter = 0;
    for (i = 0; s1[i] != '\0' || s2[j] != '\0'; i++) {
        if (s2[j] == s1[i] && s2[j] == '\0' && s1[i] == '\0')
            return (0);
        else {
            letter = s1[i] - s2[j];
            return (letter);
        }
        j++;
    }
}
