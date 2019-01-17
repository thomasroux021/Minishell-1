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
        m?str[m + 1]= '\0':0;
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
        (ret == -1)?my_putstr("Error: Command not found\n"):0;
        exit(0);
    } else {
        wait4(pid, &status, 0, &usage);
        (status == 139)?my_putstr("Error: Segmentation fault (core dumped)\n"):0;
    }
}

char **fill_table(char *buf)
{
    int j = 0;
    char **table;
    char *str;
    int k;
    int m;
    int n = 0;

    for (int i = 0; buf[i] != '\0' && buf[i] != '\n'; i += 1)
        (!i && buf[i] != ' ') || (i && buf[i - 1] == ' ' && buf[i] != ' ')?
            j += 1:0;
    (table = malloc(sizeof(char *) + (j + 1))) == NULL?exit(84):0;
    for (k = 0; buf[k] != '\0' && buf[k] != '\n'; k += 1) {
        (str = malloc(sizeof(char) * (1 + my_strlen(buf)))) == NULL?exit(84):0;
        m = 0;
        while (buf[k] != '\0' && buf[k] != '\n' && buf[k] != ' ') {
            str[m] = buf[k];
            k += 1;
            m += 1;
        }
        m?str[m] = '\0':0;
        m?table[n] = str:0;
        m?n += 1:0;
    }
    table[n] = NULL;
    return (table);
}

int main(int ac, char **env)
{
    int size = 0;
    char *buf;
    char **table;

    (ac != 1)?exit(84):0;
    while(1) {
        (buf = malloc(sizeof(char) * 1001)) == NULL?exit(84):0;
        my_putstr("> ");
        (size = read(0, buf, 1000)) == -1?exit(84):0;
        buf[size] = '\0';
        (size && buf[size - 1] != '\n')?my_putchar('\n'):0;
        (!my_strcmp(buf, "exit\n") || !my_strcmp(buf, "exit"))?exit(0):0;
        table = fill_table(buf);
        my_fork(env, table);
        free(buf);
    }
}
