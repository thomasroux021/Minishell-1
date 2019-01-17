/*
** EPITECH PROJECT, 2018
** my_swap.c
** File description:
** swap two str
*/

#include "lib.h"

void my_swap(int *a, int *b)
{
    int i = *a;

    *a = *b;
    *b = i;
}
