/*
** EPITECH PROJECT, 2018
** my_strstr.c
** File description:
** str to str
*/

#include "lib.h"

int return_char(int i, int j, char const *to_find, char *str)
{
    while (to_find[j] != '\0') {
        if (str[i + j] != to_find[j])
            break;
        j++;
    }
    return j;
}

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int j = 0;

    while (str[i] != '\0') {
        j = 0;
        j = return_char(i, j, to_find, str);
        if (to_find[j] == '\0')
            return (str + i);
        i++;
    }
    return (0);
}
