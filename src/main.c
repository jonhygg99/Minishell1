/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** replicate
*/

#include "../my.h"

void path_print2(char *path)
{
    int beg = 0;
    int j = 0;
    char *direct = malloc(sizeof(char) * my_strlen(path));

    for (int i = 0; path[i] != '\0'; i++)
        if (path[i] == '/')
            beg = i;
    my_putchar('[');
    for (++beg; path[beg] != '\0'; beg++)
        direct[j++] = path[beg];
    my_putstr(direct);
    my_putchar(']');
    my_putchar('$');
    my_putchar(' ');
    free(direct);
}

int path_print(void)
{
    char *error = "not null";
    char path[256];
    char *path2 = malloc(sizeof(char) * (256));

    error = getcwd(path, sizeof(path));
    path2 = path;
    if (error == NULL)
        perror("Error to find the path\n");
    else
        path_print2(path2);
    return (0);
}

char **env_null(char **env)
{
    if (env[0] == NULL) {
        env = malloc(sizeof(char *) * 3);
        env[0] = malloc(sizeof(char) * 20);
        env[1] = malloc(sizeof(char) * 20);
        env[0] = "PATH=/usr/bin:";
        env[1] = recuperate_home();
        env[2] = NULL;
    }
    return (env);
}

int main(int ac, char **ag, char **env)
{
    char *str;
    char *path;
    char **my_env = my_env_save(env);

    while (1) {
        path_print();
        str = get_one_line();
        if (str == NULL)
            exit(84);
        env = env_null(my_env);
        env = home_save(env);
        exit_minishell(str);
        check_command(str, env);
    }
}
