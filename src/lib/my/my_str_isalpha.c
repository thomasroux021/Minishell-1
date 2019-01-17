/*
** EPITECH PROJECT, 2018
** my_str_isalpha.c
** File description:
** str is just alpha
*/

#include "lib.h"

int my_str_isalpha(char const *str)
{
    int i = 0;
    int j = 0;

    while (str[i] != '\0') {
        if (str[i] >= 65 && str[i] <= 90)
            j += 1;
        if (str[i] >= 97 && str[i] <= 122)
            j += 1;
        i += 1;
    }
    if (i == j)
        return (1);
    return (0);
}
