/*
** EPITECH PROJECT, 2018
** my_sort_int_array.c
** File description:
** sorting number
*/

#include "lib.h"

int rev_array(int *array, int size)
{
    int mem;
    int j = 0;

    while (j != size - 1) {
        if (array[j] > array[j + 1]) {
            mem = array[j];
            array[j] = array[j + 1];
            array[j + 1] = mem;
        }
        j += 1;
    }
}

void my_sort_int_array(int *array, int size)
{
    int i = 0;
    int j;
    int mem;

    while (i != size) {
        rev_array(array, size);
        i += 1;
    }
}
