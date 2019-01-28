/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main
*/

#include "my.h"

void my_fork(char **env, char **table)
{
    struct rusage usage;
    int status;
    pid_t pid;
    char *com = table[0];
    char **path_env = my_env(env);
    int ret;

    pid = fork();
    if (!pid) {
        for (int i = 0; table[0] != NULL && path_env[i] != NULL &&
                (ret = execve(table[0], table, env)) == -1; i += 1)
            table[0] = my_realloc(path_env[i], com);
        (ret == -1)?my_putstr(com):0;
        (ret == -1)?my_putstr(": Command not found\n"):0;
        exit(0);
    }
    wait4(pid, &status, 0, &usage);
    (status == 139)?my_putstr("Segmentation fault (core dumped)\n"):0;
}

int my_exit(char *buf)
{
    int dest = 0;

    for (int i = 0; i < 5; i += 1)
        buf++;
    if ((dest = my_getnbr(buf)) != -666) {
        my_putstr("exit\n");
        exit(dest);
    }
    my_putstr("exit: Invalid syntax\n");
    return (-1);
}

int my_com(char **table, shell_t *shell, char *buf)
{
    if (!my_strcmp(table[0], "exit"))
        return (my_exit(buf));
    if (!my_strcmp(table[0], "cd"))
        return (my_cd(table, shell));
    if (!my_strcmp(table[0], "env"))
        return (print_env(table, shell->my_env));
    if (!my_strcmp(table[0], "unsetenv"))
        return (my_unsetenv(table, shell));
    if (!my_strcmp(table[0], "setenv"))
        return (my_setenv(table, shell));
    my_fork(shell->my_env, table);
    return (0);
}

void my_ctrld(char *str)
{
    my_putstr(str);
    exit(0);
}

int main(int ac, char **av, char **env)
{
    char *buf;
    size_t size = 0;
    char **table;
    shell_t *shell = malloc(sizeof(shell_t));

    (ac != 1 || shell == NULL)?exit(84):0;
    shell->my_env = cpy_env(env);
    shell->pwd = NULL;
    shell->pwd_act = NULL;
    while (1) {
        (buf = malloc(sizeof(char) * 1001)) == NULL?exit(84):0;
        (isatty(0) == 1)?my_putstr("> "):0;
        getline(&buf, &size, stdin) == -1?my_ctrld("exit\n"):0;
        (my_strlen(buf) > 1 && buf[my_strlen(buf) - 1] == '\n')?
            (buf[my_strlen(buf) - 1] = '\0'):0;
        table = fill_table(buf);
        my_com(table, shell, buf);
        free(buf);
    }
}
