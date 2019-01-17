/*
** EPITECH PROJECT, 2018
** my_strcpy.c
** File description:
** copy str
*/

#include "lib.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i += 1;
    }
    dest[i] = src[i];
    return (dest);
}
