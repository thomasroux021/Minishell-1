/*
** EPITECH PROJECT, 2018
** my_strupcase.c
** File description:
** lower in upper
*/

#include "lib.h"

char *my_strupcase(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 97 && str[i] <= 122)
            str[i] = str[i] - 32;
        i += 1;
    }
    return (str);
}
