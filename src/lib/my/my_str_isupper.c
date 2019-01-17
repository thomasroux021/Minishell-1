/*
** EPITECH PROJECT, 2018
** my_str_isupper.c
** File description:
** str is just upper
*/

#include "lib.h"

int my_str_isupper(char const *str)
{
    int i = 0;
    int j = 0;

    while (str[i] != '\0') {
        if (str[i] >= 65 && str[i] <= 90)
            j += 1;
        i += 1;
    }
    if (i == j)
        return (1);
    return (0);
}
