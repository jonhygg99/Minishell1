/*
** EPITECH PROJECT, 2019
** environment settings
** File description:
** env
*/

#include "../my.h"

char **my_env_save(char **env)
{
    char **my_env;
    int i;
    int j;

    for (i = 0; env[i] != NULL; i++);
    my_env = malloc(sizeof(char *) * (i * 2));
    for (i = 0; env[i] != NULL; i++)
        my_env[i] = malloc(sizeof(char) * (my_strlen(env[i]) + 1));
    for (i = 0; env[i] != NULL; i++)
        for (j = 0; env[i][j] != '\0'; j++)
            my_env[i][j] = env[i][j];
    my_env[i + 1] = NULL;
    return (my_env);
}

void set_environment(char **env, char **ag)
{
    int i;
    char *en;

    for (i = 0; env[i] != NULL; i++);
    en = my_strcat(ag[1], "=");
    en = my_strcat(en, ag[2]);
    env[i++] = en;
    env[i] = NULL;
}

void unset_environment(char **env, char **ag)
{
    int i;
    int j;
    int count = 0;
    int line = -1;
    char **en = my_env_save(env);

    for (i = 0; env[i] != NULL; i++) {
        for (j = 0; j <= my_strlen(ag[1]); j++)
            if (env[i][j] == ag[1][j])
                count++;
        if (count == my_strlen(ag[1]))
            line = i;
        count = 0;
    }
    if (line == -1) {
        my_putstr(ag[1]);
        my_putstr(" not found in env.\n");
    }
    for (j = 0; env[j] != NULL; j++) {
        for (int k = 0; env[i][k] != '\0'; k++)
            if (line != i)
                env[j][k] = en[j][k];
    }
    env[j] = NULL;
}

int environment_set_unset(char *str, char **env, char **ag)
{
    int i = 0;
    char *en;

    if (my_strcmp("setenv", ag[0]) == 0) {
        if (ag[1] != NULL && ag[2] != NULL)
            set_environment(env, ag);
        else
            my_putstr("Invalid setenv.\n");
    } else if (my_strcmp("unsetenv", ag[0]) == 0) {
            my_putstr("Invalid unsetenv.\n");
    } else
        return (-1);
    return (0);
}

int environment_settings(char *str, char **ag,  char **env)
{
    int i;
    char *environment = "env";
    int count = 0;

    for (i = 0; str[i] != '\0'; i++)
        if (str[i] == 'e' && str[i + 1] == 'n' && str[i + 2] == 'v')
            count++;
    if (count == 1 && my_strlen(str) == 3) {
        for (i = 0; env[i] != NULL; i++) {
            my_putstr(env[i]);
            my_putchar('\n');
        }
    } else if (count == 1 && my_strlen(str) != 3) {
        environment_set_unset(str, env, ag);
    } else
        return (-1);
    return (0);
}
