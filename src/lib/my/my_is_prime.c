/*
** EPITECH PROJECT, 2018
** my_is_prime.c
** File description:
** find prime
*/

#include "lib.h"

int my_is_prime(int nb)
{
    int i = 2;

    if (nb <= 1)
        return (0);
    while (i != nb) {
        if (nb % i == 0)
            return (0);
        else
            i += 1;
    }
    return (1);
}
