/*
** EPITECH PROJECT, 2021
** set_file
** File description:
** set_file
*/

#include <stdlib.h>
#include "my.h"

char **set_file(char const *filepath, char delim)
{
    char *buff = NULL;
    char **arg = NULL;

    buff = read_file(filepath);
    if (buff == NULL)
        return (NULL);
    arg = my_str_to_word_arr(buff, delim);
    free(buff);
    if (arg == NULL)
        return (NULL);
    return (arg);
}