/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** take_info
*/

#include <stdlib.h>
#include "my.h"

char *take_info(char const *prefixe, char *str)
{
    char *info = NULL;
    int len = 0;

    for (int i = 0; prefixe[i] == str[0]; i++)
        str++;
    len = my_strlen(str);
    info = malloc(sizeof(char) * (len + 1));
    if (info == NULL)
        return (NULL);
    info[len] = '\0';
    for (int i = 0; str[i] != '\0'; i++)
        info[i] = str[i];
    return (info);
}