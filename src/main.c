/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main
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


char **my_env(char **env)
{
    int j = 0;
    char **dest;
    char *str;
    int k = 0;
    int m = 0;

    if (pars_env(env, 46) == NULL)
        return (NULL);
    for (int i = 0; env[46][i] != '\0'; i += 1)
        (env[46][i] == ':')?j += 1:0;
    (dest = malloc(sizeof(char *) * (j + 2))) == NULL?exit(84):0;
    for (int i = 5; env[46][i] != '\0'; i += 1) {
        (str = malloc(sizeof(char) * my_strlen(env[46]))) == NULL?exit(84):0;
        m = 0;
        while (env[46][i] != '\0' && env[46][i] != ':') {
            str[m] = env[46][i];
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

void my_fork(char **env, char **table)
{
    struct rusage usage;
    int status;
    pid_t pid;
    char *com = table[0];
    char **path_env = my_env(env);
    int i = 0;
    int ret;

    pid = fork();
    if (!pid) {
        while (table[0] != NULL && path_env[i] != NULL &&
            (ret = execve(table[0], table, env)) == -1) {
            table[0] = my_realloc(path_env[i], com);
            i += 1;
        }
        (ret == -1)?my_putstr(com):0;
        (ret == -1)?my_putstr(": Command not found\n"):0;
        exit(0);
    } else {
        wait4(pid, &status, 0, &usage);
        (status == 139)?my_putstr("Segmentation fault (core dumped)\n"):0;
    }
}

int l_form(char c)
{
    if (c == ' ' || c == '\t')
        return (1);
    return (0);
}

char **fill_table(char *buf)
{
    int j = 0;
    char **table;
    char *str;
    int m;
    int n = 0;

    for (int i = 0; buf[i] != '\0'; i += 1)
        (!i && !l_form(buf[i])) || (i && l_form(buf[i - 1]) && !l_form(buf[i]))?
            j += 1:0;
    (table = malloc(sizeof(char *) + (j + 1))) == NULL?exit(84):0;
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

char *my_newpwd(char **table, char *pwd, char **env)
{
    if (pwd[my_strlen(pwd) - 1] != '/')
        pwd = my_realloc(pwd, "/");
    if (table[1] != NULL)
        pwd = my_realloc(pwd, table[1]);
    else {
        if (pars_env(env, 23) == NULL) {
            my_putstr("Error: no such file or directory\n");
            return (NULL);
        }
        pwd = my_pwd(env[23], 5);
    }
    return (pwd);
}

int my_cd(char **table, char **env)
{
    static char *pwd = NULL;
    static char *pwd_act = NULL;
    char *mem;

    pars_env(env, 21) == NULL?my_putstr("Error: no such file or directory\n"):0;
    if (pars_env(env, 21) == NULL)
        return (1);
    pwd_act == NULL?(pwd_act = my_pwd(pars_env(env, 21), 4)):0;
    mem = malloc(sizeof(char) * my_strlen(env[21]));
    if (table[1] != NULL && !my_strcmp(table[1], "-")) {
        if (pwd != NULL) {
            chdir(pwd);
            mem = pwd_act;
            pwd = pwd_act;
            pwd_act = mem;
        } else
            my_putstr("Error: no such file or directory\n");
    } else {
        (table[1] != NULL && table[2] != NULL)?my_putstr("cd: too many arguments\n"):0;
        if (chdir(mem = my_newpwd(table, pwd_act, env)) == -1)
            my_putstr("Error: no such file or directory\n");
        else {
            pwd = pwd_act;
            pwd_act = mem;
        }
    }
    return (0);
}

int main(int ac, char **env)
{
    char *buf;
    size_t size = 0;
    char **table;

    (ac != 1)?exit(84):0;
    while (1) {
        (buf = malloc(sizeof(char) * 1001)) == NULL?exit(84):my_putstr("> ");
        getline(&buf, &size, stdin) == -1?exit(84):0;
        buf == NULL?exit(84):0;
        if (!my_strcmp(buf, "exit\n") || !my_strcmp(buf, "exit") ||
            buf[0] == 0) {
            my_putstr("exit\n");
            exit(0);
        } else if (buf[0] != '\n') {
            (my_strlen(buf) && buf[my_strlen(buf) - 1] == '\n')?
                (buf[my_strlen(buf) - 1] = '\0'):0;
            table = fill_table(buf);
            !my_strcmp(table[0], "cd")?my_cd(table, env):my_fork(env, table);
        }
        free(buf);
    }
}