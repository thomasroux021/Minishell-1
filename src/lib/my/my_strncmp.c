/*
** EPITECH PROJECT, 2018
** my_strncmp.c
** File description:
** copy n str
*/

#include "lib.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;
    int a;
    int b;

    while (s1[i] != '\0' && s2[i] != '\0' && i < n) {
        a = s1[i];
        b = s2[i];
        if (a < b)
            return (a - b);
        if (a > b)
            return (a - b);
        i += 1;
    }
    return (0);
}
