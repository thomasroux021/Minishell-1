/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** include
*/

#ifndef MY_H
#define MY_H

#include "../src/lib/my/lib.h"
#include <sys/time.h>
#include <signal.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

typedef struct shell_s
{
    char **my_env;
    char *pwd_act;
    char *pwd;
    char *mem;
} shell_t;

int isacom(char *str);
int print_env(char **table, char **env);
int my_unsetenv(char **table, shell_t *shell);
int my_setenv(char **table, shell_t *shell);

char **cpy_env(char **env);
int my_cd(char **table, shell_t *s);

void handle_sigint(int sig);
void handle_sigint_f(int sig);
int my_return(char *str);
void print_err(int s);

void my_returnerr(char *str, char *err);
int str_alphanum(char *str);
int char_isalpha(char c);

char *my_realloc(char *str, char *src);
char **my_env(char **env);
void my_fork(char **env, char **table);
char **fill_table(char *buf);
char *my_pwd(char *pwd, int j);
int pars_env(char **env, char *str);
char *my_newpwd(char **table, char *pwd, char **env);
int my_cd(char **table, shell_t *shell);
int l_form(char c);
int parser_env(char **env, char *str);
char *my_pwd(char *pwd, int j);
#endif
