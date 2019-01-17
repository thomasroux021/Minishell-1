/*
** EPITECH PROJECT, 2018
** my_str_isnum.c
** File description:
** str is just a number
*/

#include "lib.h"

int my_str_isnum(char const *str)
{
    int i = 0;
    int j = 0;
    int m = 0;

    while (str[i] != '\0') {
        if (str[i] >= 48 && str[i] <= 57)
            j += 1;
        if (str[i] == 45 && m == 0)
            j += 1;
        m = 1;
        i += 1;
    }
    if (i == j)
        return (1);
    return (0);
}
