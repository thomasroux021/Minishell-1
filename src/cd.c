/*
** EPITECH PROJECT, 2019
** cd.c
** File description:
** manage cd
*/

#include "my.h"

char **cpy_env(char **env)
{
    char **dest;
    char *str;
    int i;
    int j;

    for (i = 0; env[i] != NULL; i += 1);
    (dest = malloc(sizeof(char *) * (i + 1))) == NULL?exit(84):0;
    for (j = 0; env[j] != NULL; j += 1) {
        (str = malloc(sizeof(char) * (my_strlen(env[j]) + 1))) == NULL?
            exit(84):0;
        dest[j] = my_strcpy(str, env[j]);
    }
    dest[j] = NULL;
    return (dest);
}

char *my_newpwd(char **table, char *pwd, char **env)
{
    if (pwd[my_strlen(pwd) - 1] != '/')
        pwd = my_realloc(pwd, "/");
    if (table[1] != NULL) {
        if (!my_strcmp(table[1], "~")) {
            my_puterror("No $home variable set.\n");
            return (NULL);
        }
        pwd = my_realloc(pwd, table[1]);
    } else {
        if (pars_env(env, "HOME=") == -1) {
            my_puterror("Error: No home directory.\n");
            return (NULL);
        }
        pwd = my_pwd(env[pars_env(env, "HOME=")], 5);
    }
    return (pwd);
}

int cd_dash(shell_t *s)
{
    if (s->pwd != NULL) {
        if (chdir(s->pwd) == -1) {
            perror("Error");
            return (1);
        }
        s->mem = s->pwd;
        s->pwd = s->pwd_act;
        s->pwd_act = s->mem;
    } else {
        if (pars_env(s->my_env, "HOME=") == -1) {
            my_puterror("Error: No home directory.\n");
            return (-1);
        }
        s->mem = s->pwd_act;
        s->pwd_act = my_pwd(s->my_env[pars_env(s->my_env, "HOME=")], 5);
        s->pwd = s->mem;
        chdir(s->pwd_act);
    }
    return (0);
}

void inv_pwd(shell_t *s)
{
    s->pwd = s->pwd_act;
    s->pwd_act = s->mem;
}

int my_cd(char **table, shell_t *s)
{
    int nb_pwd;
    char cwd[400];

    if (s->pwd_act == NULL) {
        (s->pwd_act = malloc(sizeof(char) * 400)) == NULL?exit(84):0;
        s->pwd_act = my_strcpy(s->pwd_act, (getcwd(cwd, sizeof(cwd))));
    }
    (s->mem = malloc(sizeof(char) * 400)) == NULL?exit(84):0;
    if (table[1] != NULL && !my_strcmp(table[1], "-")) {
        cd_dash(s);
    } else {
        if (table[1] != NULL && table[2] != NULL)
            my_puterror("cd: Too many arguments.\n");
        if ((s->mem = my_newpwd(table, s->pwd_act, s->my_env)) != NULL)
            (chdir(s->mem) == -1)?perror("Error"):inv_pwd(s);
    }
    while ((nb_pwd = pars_env(s->my_env, "PWD=")) == -1)
        my_setenv(my_pwdenv(), s);
    s->my_env[nb_pwd] = my_realloc("PWD=", s->pwd_act);
    return (0);
}
