/*
** EPITECH PROJECT, 2018
** my_index_of
** File description:
** return the index of the first occurence of a char in a
** char *, -1 if the char is not in the char *
*/

#include "lib.h"

int my_index_of(char c, char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == c)
            return (i);
        i++;
    }
    return (-1);
}
