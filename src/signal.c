/*
** EPITECH PROJECT, 2019
** signal.c
** File description:
** manage sig
*/

#include "my.h"

void handle_sigint(int sig)
{
    if (sig == SIGINT) {
        my_putstr("\n> ");
    }
}

void handle_sigint_f(int sig)
{
    if (sig == SIGINT) {
        my_putchar('\n');
    }
}

int isacom(char *str)
{
    int j = 0;

    for (int i = 0; str[i]; i += 1)
        if (str[i] == '/')
            j += 1;
    if (!j)
        return (1);
    return (0);
}

int my_return(char *str)
{
    my_puterror(str);
    return (-1);
}

void print_err(int s)
{
    if (WTERMSIG(s) + 128 != 136)
        my_puterror(strsignal(WTERMSIG(s)));
    else
        my_puterror("Floating exception");
    if (WCOREDUMP(s))
        my_puterror(" (core dumped)\n");
    else
        my_puterror("\n");
}
