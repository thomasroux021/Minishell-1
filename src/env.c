/*
** EPITECH PROJECT, 2019
** env.c
** File description:
** manage env
*/

#include "my.h"

int print_env(char **table, char **env)
{
    if (table[1] != NULL) {
        my_puterror("env: Too many arguments.\n");
        return (-1);
    }
    for (int i = 0; env[i] != NULL; i += 1) {
        my_putstr(env[i]);
        my_putchar('\n');
    }
    return (0);
}

void my_unalloc(shell_t *shell, int nb)
{
    char **dest;
    int i;
    int k = 0;
    int j;

    for (i = 0; shell->my_env[i] != NULL; i += 1);
    (dest = malloc(sizeof(char *) * (i + 1))) == NULL?exit(84):0;
    for (j = 0; shell->my_env[j] != NULL; j += 1) {
        dest[j - k] = shell->my_env[j];
        if (j == nb)
            k = 1;
    }
    dest[j - k] = NULL;
    shell->my_env = dest;
}

int my_unsetenv(char **table, shell_t *shell)
{
    if (table[1] == NULL) {
        my_puterror("unsetenv: Too few arguments.\n");
        return (-1);
    }
    for (int i = 1; table[i] != NULL; i += 1) {
        if (pars_env(shell->my_env, my_realloc(table[i], "=")) != -1)
            my_unalloc(shell, pars_env(shell->my_env, table[i]));
    }
    return (0);
}

int my_envalloc(char *str, shell_t *shell)
{
    char **dest;
    int i;
    int j;

    for (i = 0; shell->my_env[i] != NULL; i += 1);
    (dest = malloc(sizeof(char *) * (i + 2))) == NULL?exit(84):0;
    if (pars_env(shell->my_env, my_realloc(str, "=")) == -1) {
        for (j = 0; shell->my_env[j] != NULL; j += 1)
            dest[j] = shell->my_env[j];
        dest[j] = my_realloc(str, "=");
        dest[j + 1] = NULL;
        shell->my_env = dest;
        return (j);
    } else
        return (pars_env(shell->my_env, my_realloc(str, "=")));
}

int my_setenv(char **table, shell_t *shell)
{
    int nb;

    if (table[1] == NULL)
        return (print_env(table, shell->my_env));
    if (table[2] != NULL && table[3] != NULL)
        return (my_return("setenv: Too many arguments.\n"));
    if (!char_isalpha(table[1][0])) {
        my_puterror("setenv: Variable name must begin with");
        my_puterror(" a letter.\n");
        return (-1);
    } else if (!str_alphanum(table[1])){
        my_puterror("setenv: Variable name must contain");
        my_puterror(" alphanumeric characters.\n");
        return (-1);
    }
    nb = my_envalloc(table[1], shell);
    if (table[2] != NULL)
        shell->my_env[nb] = my_realloc(my_realloc(table[1], "="), table[2]);
    return (1);
}
