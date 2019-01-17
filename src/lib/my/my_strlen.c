/*
** EPITECH PROJECT, 2018
** my_strlen.c
** File description:
** calculate the lenght of str
*/

#include "lib.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i = i + 1;
    return (i);
}
