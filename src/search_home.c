/*
** EPITECH PROJECT, 2019
** search_home
** File description:
** home save in env
*/

#include "../my.h"

char **home_save(char **env)
{
    int i;
    int line = -1;
    char *home;

    for (i = 0; env[i] != NULL; i++) {
        if (env[i][0] == 'H' && env[i][1] == 'O' && env[i][2] == 'M' &&
            env[i][3] == 'E')
            line = i;
    }
    if (line == -1) {
        home = recuperate_home();
        for (i = 0; env[i] != NULL; i++);
        for (int j = 0; home[j] != '\0'; j++)
            env[i][j] = home[j];
        env[++i] = NULL;
    }
    return (env);
}

char *recuperate_home(void)
{
    int i = 0;
    char *home = malloc(sizeof(char) * (256));
    char *path = malloc(sizeof(char) * (256));
    int slash = 0;
    char *error = "not null";

    error = getcwd(home, sizeof(char) * 10000);
    my_putstr(home);
    if (error == NULL)
        perror("Error to find the home\n");
    for (i = 0; home[i] && slash != 3; i++) {
        if (home[i] == '/')
            slash++;
        if (slash == 3)
            break;
    }
    for (int j = 0; j < i; j++)
        path[j] = home[j];
    path = my_strcat("HOME=", path);
    return (path);
}
