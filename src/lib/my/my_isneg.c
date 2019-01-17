/*
** EPITECH PROJECT, 2018
** my_isneg.c
** File description:
** find negative number
*/

#include "lib.h"

int my_isneg(int n)
{
    int result;

    if (n >= 0)
        result = 80;
    else
        result = 78;
    my_putchar(result);
    my_putchar(10);
}
