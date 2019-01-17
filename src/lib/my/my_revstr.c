/*
** EPITECH PROJECT, 2018
** my_revstr.c
** File description:
** reverse str
*/

#include "lib.h"

char *my_revstr(char *str)
{
    int i = 0;
    int j = 0;
    char memo[2] = {0};

    while (str[i] != '\0')
        i += 1;
    while (j < i / 2) {
        memo[0] = str[j];
        str[j] = str[i - j - 1];
        str[i - j - 1] = memo[0];
        j += 1;
    }
    return (str);
}
