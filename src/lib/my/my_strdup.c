/*
** EPITECH PROJECT, 2018
** my_strdup.c
** File description:
** my_strdup
*/

#include "lib.h"
#include <stdlib.h>

char *my_strdup(char const *str)
{
    char *r = malloc(sizeof(char) * (my_strlen(str) + 1));

    (r == NULL)?exit(84):0;
    return (my_strcpy(r, str));
}
