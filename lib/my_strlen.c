/*
** EPITECH PROJECT, 2018
** my_strlen
** File description:
** length of the string
*/

int my_strlen(char const *str)
{
    int i;
    int len;

    len = 0;
    for (i = 0; str[len] != '\0'; i++) {
        len++;
    }
    return (len);
}
