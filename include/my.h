/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** include
*/

#ifndef MY_H
#define MY_H

#ifndef READ_SIZE
#define READ_SIZE 10
#endif

#include "../src/lib/my/lib.h"
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

char *my_strtocpy(char *str, char *src);
char *get_buf(int fd);
int size_line(char *buf, int i);
char *get_next_line(int fd);
char *my_realloc(char *str, char *src);
char **my_env(char **env);
void my_fork(char **env, char **table);
char **fill_table(char *buf);
char *my_pwd(char *pwd, int j);
char *pars_env(char **env, int nb);
char *my_newpwd(char **table, char *pwd, char **env);
int my_cd(char **table, char **env);
int l_form(char c);
char *pars_env(char **env, int nb);
int parser_env(char **env, int nb);
char *my_pwd(char *pwd, int j);
#endif
