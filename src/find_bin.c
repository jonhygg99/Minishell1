/*
** EPITECH PROJECT, 2019
** find_bin
** File description:
** find bin
*/

#include "../my.h"

char **add_bin_value(char **path, int line, char **env)
{
    int i;
    int j = 0;
    int k = 0;

    for (i = 5; env[line][i] != '\0'; i++) {
        if (env[line][i] == ':') {
            j++;
            k = 0;
            i++;
        }
        path[j][k++] = env[line][i];
        path[j][k] = '/';
    }
    path[++j] = NULL;
    return (path);
}

char **find_bin(char **env)
{
    int i;
    int point = 1;
    int line = 0;
    char **path;

    for (i = 0; env[i] != NULL; i++) {
        if (env[i][0] == 'P' && env[i][1] == 'A' && env[i][2] == 'T' &&
            env[i][3] == 'H')
            line = i;
    }
    for (i = 0; env[line][i] != '\0'; i++)
        if (env[line][i] == ':')
            point++;
    path = malloc(sizeof(char *) * (point + 1));
    for (i = 0; i <= point; i++)
        path[i] = malloc(sizeof(char *) * 256);
    path = add_bin_value(path, line, env);
    return (path);
}
