/*
** EPITECH PROJECT, 2018
** my_strcapitalize.c
** File description:
** str become capitalize
*/

#include "lib.h"

int is_char(char *str, int i)
{
    if (str[i] <= 47 || str[i] >= 123)
        return (1);
    if (str[i] >= 58 && str[i] <= 64)
        return (1);
    if (str[i] >= 91 && str[i] <= 96)
        return (1);
    return (2);
}

char *my_strcapitalize(char *str)
{
    int i = 0;
    int fst = 1;
    int letter;

    while (str[i] != '\0') {
        if (str[i] >= 65 && str[i] <= 90 && fst == 2)
            str[i] = str[i] + 32;
        if (str[i] >= 97 && str[i] <= 122 && fst == 1) {
            str[i] = str[i] - 32;
            fst = 2;
        }
        fst = is_char(str, i);
        i += 1;
    }
    return (str);
}
