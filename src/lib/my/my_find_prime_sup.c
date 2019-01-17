/*
** EPITECH PROJECT, 2018
** my_find_prime_sup.c
** File description:
** find prime
*/

#include "lib.h"

int my_find_prime_sup(int nb)
{
    int i = 2;
    int result;

    if (nb <= 1)
        nb = 2;
    while (i != nb) {
        if (nb % i == 0) {
            result = (my_find_prime_sup(nb + 1));
            return (result);
        } else
            i += 1;
    }
    return (nb);
}
