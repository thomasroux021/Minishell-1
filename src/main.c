/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main
*/

#include "my.h"

void my_fork(char **env, char **table)
{
    int s;
    pid_t pid;
    char *com = table[0];
    char **path_env = my_env(env);
    int ret = -1;

    signal(SIGINT, handle_sigint_f);
    if (!(pid = fork())) {
        (!is_dir(table[0]) || (access(table[0], X_OK) == -1 && is_dir(table[0])
            != -1))?my_returnerr(table[0], ": Permission denied.\n"):0;
        (isacom(table[0]))?(table[0] = my_realloc("abcde", com)):0;
        path_env[0] == NULL?(ret = execve(table[0], table, env)):0;
        for (int i = 0; table[0] != NULL && path_env[i] != NULL &&
            (ret = execve(table[0], table, env)) == -1; i += 1)
            table[0] = my_realloc(path_env[i], com);
        (ret == -1)?my_returnerr(com, ": Command not found.\n"):0;
    }
    waitpid(pid, &s, 0);
    (WIFSIGNALED(s))?print_err(s):0;
}

int my_exit(char *buf, shell_t *s, char **table)
{
    int dest = 0;

    for (int i = 0; i < 5; i += 1)
        buf++;
    if ((dest = my_getnbr(buf)) != -666) {
        my_putstr("exit\n");
        for (int i = 0; table[i] != NULL; i += 1)
            free(table[i]);
        free(table);
        for (int i = 0; s->my_env[i] != NULL; i += 1)
            free(s->my_env[i]);
        free(s->my_env);
        s->pwd != NULL?free(s->pwd):0;
        s->pwd_act != NULL?free(s->pwd_act):0;
        free(s);
        exit(dest);
    }
    my_puterror("exit: Invalid syntax.\n");
    return (-1);
}

int my_com(char **table, shell_t *shell, char *buf)
{
    if (buf[0] == '\n')
        return (-1);
    if (!my_strcmp(table[0], "exit"))
        return (my_exit(buf, shell, table));
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
    init_shell(shell);
    while (1) {
        signal(SIGINT, handle_sigint);
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
