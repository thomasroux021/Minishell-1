/*
** EPITECH PROJECT, 2018
** my_putstr.c
** File description:
** print str
*/

#include "lib.h"

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i += 1;
    }
}

void my_puterror(char *str)
{
    write(2, str, my_strlen(str));
}
