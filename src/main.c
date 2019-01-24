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
    } else {
        wait4(pid, &status, 0, &usage);
        (status == 139)?my_putstr("Segmentation fault (core dumped)\n"):0;
    }
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

int cd_dash(char **pwd, char **mem, char **pwd_act)
{
    if (*pwd != NULL) {
        if (chdir(*pwd) == -1) {
            my_putstr("Error: no such file or directory\n");
            return (1);
        }
        *mem = *pwd_act;
        *pwd = *pwd_act;
        *pwd_act = *mem;
    } else
        my_putstr("Error: no such file or directory\n");
    return (0);
}

int my_cd(char **table, char **env)
{
    static char *pwd = NULL;
    static char *pwd_act = NULL;
    char *mem;

    if (parser_env(env, 21))
        return (1);
    pwd_act == NULL?(pwd_act = my_pwd(pars_env(env, 21), 4)):0;
    (mem = malloc(sizeof(char) * my_strlen(env[21]))) == NULL?exit(84):0;
    if (table[1] != NULL && !my_strcmp(table[1], "-")) {
        cd_dash(&pwd, &mem, &pwd_act);
    } else {
        (table[1] != NULL && table[2] != NULL)?
            my_putstr("cd: too many arguments\n"):0;
        if (chdir(mem = my_newpwd(table, pwd_act, env)) == -1)
            my_putstr("Error: no such file or directory\n");
        else {
            pwd = pwd_act;
            pwd_act = mem;
        }
    }
    return (0);
}

int main(int ac, char **av, char **env)
{
    char *buf;
    size_t size = 0;
    char **table;

    (ac != 1)?exit(84):0;
    while (1) {
        (buf = malloc(sizeof(char) * 1001)) == NULL?exit(84):my_putstr("> ");
        getline(&buf, &size, stdin) == -1 || buf == NULL?exit(84):0;
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
