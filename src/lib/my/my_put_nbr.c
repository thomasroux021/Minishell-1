/*
** EPITECH PROJECT, 2018
** my_put_nbr.c
** File description:
** print number
*/

#include "lib.h"

int my_put_nbr(int nb)
{
    int i;
    long ln;

    ln = nb;
    if (ln < 0) {
        my_putchar(45);
        ln = -ln;
    }
    if (ln > 9) {
        my_put_nbr(ln / 10);
        i = ln % 10;
        my_putchar(i + 48);
    } else
        my_putchar(ln + 48);
}
