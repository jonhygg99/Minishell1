/*
** EPITECH PROJECT, 2019
** get_next_line
** File description:
**
*/

#include "../my.h"

char *remove_tabs(char *str)
{
    int i;
    int j = 0;
    char *save = malloc(sizeof(char) * my_strlen(str) + 1);

    for (i = 0; str[i]; i++) {
        if (str[i] == '\t') {
            str[i] = ' ';
        } else
            save[j++] = str[i];
    }
    save[i] = '\0';
    return (save);
}

char *remove_beg_end_space(char *str)
{
    int i;
    int j = 0;
    int beg = 0;
    int end = 0;
    char *save = malloc(sizeof(char) * my_strlen(str) + 1);

    for (i = 0; i <= my_strlen(str); i++) {
        if (str[i] != ' ') {
            beg = i;
            break;
        }
    }
    for (i = 0; i < my_strlen(str); i++) {
        if (str[i] != ' ')
            end = i;
    }
    for (i = beg; i <= end; i++)
        save[j++] = str[i];
    save[j] = '\0';
    return (save);
}

char *remove_mid_space(char *save)
{
    int i;
    int j = 0;
    int k = 0;
    char *str = malloc(sizeof(char) * my_strlen(save) + 1);

    for (i = 0; i < my_strlen(save); i++) {
        if (save[i] != ' ')
            str[j++] = save[i];
        else if (save[i] == ' ' && save[i + 1] != ' ')
            str[j++] = save[i];
    }
    str[j] = '\0';
    return (str);
}

char *remove_trash(char *save)
{
    if (my_strlen(save) != 0) {
        save = remove_tabs(save);
        save = remove_beg_end_space(save);
        save = remove_mid_space(save);
    }
    return (save);
}

char *get_one_line(void)
{
    char *buff = NULL;
    char *save;
    int j = 0;

    buff = malloc(sizeof(char) * 2);
    save = malloc(sizeof(char) * 1000000);
    while (read(0, buff, 1)) {
        if (buff[0] != '\n')
            save[j++] = buff[0];
        else {
            save[j] = '\0';
            free(buff);
            save = remove_trash(save);
            return (save);
        }
    }
    free(save);
    free(buff);
    return (NULL);
}
