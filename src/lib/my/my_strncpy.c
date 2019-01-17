/*
** EPITECH PROJECT, 2018
** my_strncpy.c
** File description:
** copy n str
*/

#include "lib.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    int plus = 0;

    while (i != n) {
        if (src[i] == '\0') {
            dest[i] = '\0';
            plus = 1;
        }
        else if (plus == 1)
            dest[i] == '\0';
        else
            dest[i] = src[i];
        i += 1;
    }
    return (dest);
}
