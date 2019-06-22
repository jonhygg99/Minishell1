/*
** EPITECH PROJECT, 2019
** command
** File description:
** command functions
*/

#include "../my.h"

int exit_minishell(char *str)
{
    int i;
    int count = 0;
    char *compare = "exit";

    for (i = 0; str[i] != '\0'; i++)
        if (str[i] == compare[i])
            count++;
    if (count != 4 || i > 4)
        return (0);
    my_putstr("exit");
    my_putchar('\n');
    exit(0);
}

int exe_command(char *str, char **env, char **ag)
{
    char *exe;
    char **bin = find_bin(env);
    int tenedor = fork();
    int pid = getpid();
    int status = 0;

    if (tenedor == -1)
        exit(84);
    else if (tenedor == 0) {
        for (int i = 0; bin[i] != NULL; i++) {
            exe = my_strcat(bin[i], ag[0]);
            if (execve(exe, ag, env) == -1);
        }
        return (-1);
    } if (tenedor > 0)
          waitpid(tenedor, &status, 0);
}

int check_command(char *str, char **env)
{
    int i = 0;
    int error = 0;
    char **ag = point_2_pointer(str);

    error = change_directory(str, ag, env);
    if (error == -1)
        error = environment_settings(str, ag, env);
    if (error == -1)
        error = exe_command(str, env, ag);
    if (error == -1 && my_strlen(str) != 0) {
        my_putstr(str);
        my_putstr(": Command not found.\n");
        exit(84);
    }
    return (0);
}
