/*
** EPITECH PROJECT, 2018
** my_strcat.c
** File description:
** copy str
*/

#include "lib.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int j = 0;

    while (dest[j] != '\0')
        j += 1;
    while (src[i] != '\0') {
        dest[j + i] = src[i];
        i += 1;
    }
    return (dest);
}
