/*
** EPITECH PROJECT, 2019
** parser.c
** File description:
** pars
*/

#include "my.h"

int l_form(char c)
{
    if (c == ' ' || c == '\t')
        return (1);
    return (0);
}

char *my_pwd(char *pwd, int j)
{
    char *str = malloc(sizeof(char) * my_strlen(pwd));
    int i;

    if (str == NULL)
        exit(84);
    for (i = 0; pwd[i + j]; i += 1)
        str[i] = pwd[i + j];
    str[i] = '\0';
    return (str);
}

int pars_env(char **env, char *str)
{
    int br = 0;

    for (int i = 0; env[i] != NULL; i += 1) {
        for (int j = 0; str[j] != '\0' && !br; j += 1)
            (env[i][j] != '\0' && str[j] == env[i][j])?0:(br = 1);
        if (!br)
            return (i);
        else
            br = 0;
    }
    return (-1);
}

int parser_env(char **env, char *str)
{
    int mem;

    if ((mem = pars_env(env, str)) == -1) {
        my_puterror("Error: no such file or directory\n");
        return (1);
    }
    return (mem);
}
