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

    for (i = 0; pwd[i + j]; i += 1)
        str[i] = pwd[i + j];
    str[i] = '\0';
    return (str);
}

char *pars_env(char **env, int nb)
{
    int i;

    for (i = 2; env[i] != NULL; i += 1)
        if (i == nb)
            return (env[nb]);
    return (NULL);
}

int parser_env(char **env, int nb)
{
    if (pars_env(env, nb) == NULL) {
        my_putstr("Error: no such file or directory\n");
        return (1);
    }
    return (0);
}
