/*
** EPITECH PROJECT, 2018
** my_strncat.c
** File description:
** copy n str
*/

#include "lib.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int j = 0;

    while (dest[j] != '\0')
        j += 1;
    while (src[i] != '\0' && i < nb) {
        dest[j + i] = src[i];
        i += 1;
    }
    return (dest);
}
