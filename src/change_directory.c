/*
** EPITECH PROJECT, 2019
** change_directory
** File description:
** cd
*/

#include "../my.h"

char *search_home(char *str, char **env)
{
    int i;
    int j = 0;
    int line;
    char *home;

    for (i = 0; env[i] != NULL; i++) {
	if (env[i][0] == 'H' && env[i][1] == 'O' && env[i][2] == 'M'
            && env[i][3] == 'E')
            line = i;
    }
    for (i = 0; env[line][i] != '\0'; i++);
    home = malloc(sizeof(char) * (i - 4));
    for (i = 5; env[line][i] != '\0'; i++)
        home[j++] = env[line][i];
    return (home);
}

void bad_directory_msg(char **ag)
{
    my_putstr(ag[0]);
    my_putstr(": ");
    if (ag[2] != NULL)
        my_putstr("too many arguments\n");
    else if (access(ag[1], F_OK) != 0) {
        my_putstr(ag[1]);
        my_putstr(": No such file or directory\n");
    } else {
        my_putstr(ag[1]);
        my_putstr(": Not a directory\n");
    }
}

int change_directory(char *str, char **ag, char **env)
{
    char *home;
    int error = 0;

    if (str[0] == 'c' && str[1] == 'd' && my_strlen(ag[0]) == 2) {
        if (ag[1] == NULL) {
            home = search_home(str, env);
            chdir(home);
            free(home);
        } else
            error = chdir(ag[1]);
        if (error == -1)
            bad_directory_msg(ag);
        return (0);
    }
    return (-1);
}
