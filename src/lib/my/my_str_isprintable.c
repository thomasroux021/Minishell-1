/*
** EPITECH PROJECT, 2018
** my_str_isprintable.c
** File description:
** str don't contain non printable char
*/

#include "lib.h"

int my_str_isprintable(char const *str)
{
    int i = 0;
    int j = 0;

    while (str[i] != '\0') {
        if (str[i] >= 32 && str[i] <= 126)
            j += 1;
        i += 1;
    }
    if (i == j)
        return (1);
    return (0);
}
