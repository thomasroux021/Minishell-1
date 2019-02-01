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
    for (int i = 0; str[i]; i += 1) {
        if ((!i && str[i] == '/') ||
            (i == 1 && str[i] == '/' && str[i - 1] == '.'))
            return (0);
    }
    return (1);
}

int my_return(char *str)
{
    my_puterror(str);
    return (-1);
}

void print_err(int s, shell_t *shell)
{
    my_puterror(strsignal(WTERMSIG(s)));
    shell->ex_s = WTERMSIG(s) + 128;
    if (WCOREDUMP(s))
        my_puterror(" (core dumped)\n");
    else
        my_puterror("\n");
}
