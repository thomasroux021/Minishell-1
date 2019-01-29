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
