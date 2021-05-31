/*
** EPITECH PROJECT, 2021
** display_helper
** File description:
** display_helper
*/

#include <stdlib.h>

char *read_file(char const *filepath);

void my_putstr(char const *str);

int display_helper(char const *filepath)
{
    char *helper = NULL;

    helper = read_file(filepath);
    if (helper == NULL)
        return (84);
    my_putstr(helper);
    free(helper);
    return (0);
}