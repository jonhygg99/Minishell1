/*
** EPITECH PROJECT, 2019
** 
** File description:
** 
*/

#ifndef _MY_H_
#define _MY_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

char *get_one_line(void);
char *my_strcat(char *dest, char const *src);
char **point_2_pointer(char *str);
int check_command(char *str, char **env);
char **find_bin(char **env);
int exit_minishell(char *str);
char **my_env_save(char **env);
char *remove_beg_end_space(char *str);
char *remove_mid_space(char *save);
int environment_settings(char *str, char **ag,  char **env);
char *recuperate_home(void);
char **home_save(char **env);
int change_directory(char *str, char **ag, char **env);
void my_putstr(char const *str);
void my_put_nbr(int nb);
void my_putchar(char c);
int my_strcmp(char const *s1, char const *s2);
int my_strlen(char const *str);
char *my_itoa(int nb);

#endif
