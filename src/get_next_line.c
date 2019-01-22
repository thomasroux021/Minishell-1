/*
** EPITECH PROJECT, 2018
** get_next_line.c
** File description:
** getnextline
*/

#include "my.h"

char *my_strtocpy(char *str, char *src)
{
    int i;
    int j;
    int k;
    int m;
    char *dest;

    for (i = 0; str[i] != '\0'; i += 1);
    for (j = 0; src[j] != '\0'; j += 1);
    dest = malloc(sizeof(char) * (i + j + 1));
    if (dest == NULL)
        return (NULL);
    for (k = 0; k < i; k += 1)
        dest[k] = str[k];
    for (m = 0; k + m < i + j; m += 1)
        dest[k + m] = src[m];
    free(str);
    free(src);
    dest[k + m] = '\0';
    return (dest);
}

char *get_buf(int fd)
{
    int size;
    char *str = malloc(sizeof(char) * (READ_SIZE + 1));
    char *dest = malloc(sizeof(char) * (READ_SIZE + 1));

    if (str == NULL || dest == NULL)
        return (NULL);
    dest[0] = '\0';
    while ((size = read(fd, str, READ_SIZE)) == READ_SIZE) {
        if (size <= 0)
            return (NULL);
        str[READ_SIZE] = '\0';
        dest = my_strtocpy(dest, str);
        str = malloc(sizeof(char) * (READ_SIZE + 1));
        if (dest == NULL || str == NULL)
            return (NULL);
    }
    str[size] = '\0';
    return (my_strtocpy(dest, str));
}

int size_line(char *buf, int i)
{
    int j = 0;

    if (buf[i] == '\0')
        return (-1);
    while (buf[i + j] != '\0' && buf[i + j] != '\n')
        j += 1;
    return (j);
}

char *get_next_line(int fd)
{
    int count = 0;
    char *buf = NULL;
    int i;
    char *dest;

    if (fd == -1 || READ_SIZE <= 0 || count == -1)
        return (NULL);
    (!buf)?(buf = get_buf(fd)):0;
    if (buf == NULL || size_line(buf, count) == -1)
        return (NULL);
    dest = malloc(sizeof(char) * (size_line(buf, count) + 1));
    if (dest == NULL)
        return (NULL);
    for (i = 0; i < size_line(buf, count); i += 1)
        dest[i] = buf[i + count];
    dest[i] = '\0';
    count = (buf[count + i] != '\0' && buf[count + i] == '\n')?count + i + 1:-1;
    return (dest);
}
