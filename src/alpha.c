/*
** EPITECH PROJECT, 2019
** alpha.c
** File description:
** isalpha
*/

#include "my.h"

int char_isalpha(char c)
{
    if (c >= 65 && c <= 90)
        return (1);
    if (c >= 97 && c <= 122)
        return (2);
    if (c == 95)
        return (3);
    return (0);
}

int str_alphanum(char *str)
{
    for (int i = 0; str[i]; i += 1) {
        if (!char_isalpha(str[i]) && (str[i] < 48 || str[i] > 57))
            return (0);
    }
    return (1);
}

void my_returnerr(char *str, char *err)
{
    my_puterror(str);
    my_puterror(err);
    exit(0);
}

int is_dir(char *file)
{
    struct stat fs;

    if (lstat(file, &fs) == -1)
        return (-1);
    if (S_ISDIR(fs.st_mode))
        return (0);
    return (1);
}

char **my_pwdenv(void)
{
    char **str = malloc(sizeof(char *) * 3);

    if (str == NULL)
        exit(84);
    str[0] = "setenv";
    str[1] = "PWD";
    str[2] = NULL;
    return (str);
}
