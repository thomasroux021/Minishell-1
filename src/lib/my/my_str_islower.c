/*
** EPITECH PROJECT, 2018
** my_str_islower.c
** File description:
** str is just lower
*/

#include "lib.h"

int my_str_islower(char const *str)
{
    int i = 0;
    int j = 0;

    while (str[i] != '\0') {
        if (str[i] >= 97 && str[i] <= 122)
            j += 1;
        i += 1;
    }
    if (i == j)
        return (1);
    return (0);
}
