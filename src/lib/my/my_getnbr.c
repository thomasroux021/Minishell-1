/*
** EPITECH PROJECT, 2018
** my_getnbr.c
** File description:
** find number
*/

#include "lib.h"
#include <stdlib.h>

int my_char_isnum(char str)
{
    if (str >= 48 && str <= 57)
        return (1);
    return (0);
}

int my_getnbr(char const *str)
{
    int i = 0;
    int neg = 0;
    int num = 0;

    while (str[i] != '\0') {
        if (!i && str[i] == 45)
            neg = 1;
        else if (my_char_isnum(str[i]))
            num = num * 10 + str[i] - 48;
        else
            return (-666);
        i += 1;
    }
    if (neg == 1)
        return (-num);
    return (num);
}
