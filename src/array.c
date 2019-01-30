/*
** EPITECH PROJECT, 2019
** array.c
** File description:
** create array
*/

#include "my.h"

char *my_realloc(char *str, char *src)
{
    int i;
    int j;
    int k;
    int m;
    char *dest;

    for (i = 0; str[i] != '\0'; i += 1);
    for (j = 0; src[j] != '\0'; j += 1);
    dest = malloc(sizeof(char) * (i + j + 1));
    (dest == NULL)?exit(84):0;
    for (k = 0; k < i; k += 1)
        dest[k] = str[k];
    for (m = 0; k + m < i + j; m += 1)
        dest[k + m] = src[m];
    dest[k + m] = '\0';
    return (dest);
}

char **putstr_array(char **table, char *buf)
{
    int m;
    int n = 0;
    char *str;

    for (int k = 0; buf[k] != '\0'; k += 1) {
        (str = malloc(sizeof(char) * (1 + my_strlen(buf)))) == NULL?exit(84):0;
        m = 0;
        while (buf[k] != '\0' && !l_form(buf[k])) {
            str[m] = buf[k];
            k += 1;
            m += 1;
        }
        m?str[m] = '\0':0;
        m?table[n] = str:0;
        m?n += 1:0;
        if (buf[k] == '\0')
            break;
    }
    table[n] = NULL;
    return (table);
}

char **fill_table(char *buf)
{
    int j = 0;
    char **table;

    for (int i = 0; buf[i] != '\0'; i += 1)
        (!i && !l_form(buf[i])) || (i && l_form(buf[i - 1]) && !l_form(buf[i]))?
            j += 1:0;
    (table = malloc(sizeof(char *) * (j + 1))) == NULL?exit(84):0;
    return (putstr_array(table, buf));
}

char **env_toarray(char **env, char **dest, int path)
{
    char *str;
    int k = 0;
    int m;

    for (int i = 5; env[path][i - 1] != '\0'; i += 1) {
        (str = malloc(sizeof(char) * my_strlen(env[path]))) == NULL?exit(84):0;
        m = 0;
        while (env[path][i] != '\0' && env[path][i] != ':') {
            str[m] = env[path][i];
            m += 1;
            i += 1;
        }
        m?str[m] = '/':0;
        m?str[m + 1] = '\0':0;
        m?dest[k] = str:0;
        m?k += 1:0;
    }
    dest[k] = NULL;
    return (dest);
}

char **my_env(char **env)
{
    int j = 0;
    char **dest;
    int n_path;

    if ((n_path = pars_env(env, "PATH=")) == -1) {
        (dest = malloc(sizeof(char *) * 1)) == NULL?exit(84):0;
        dest[0] = NULL;
        return (dest);
    }
    for (int i = 0; env[n_path][i] != '\0'; i += 1)
        (env[n_path][i] == ':')?j += 1:0;
    (dest = malloc(sizeof(char *) * (j + 4))) == NULL?exit(84):0;
    return (env_toarray(env, dest, n_path));
}
