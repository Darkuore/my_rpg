/*
** EPITECH PROJECT, 2021
** my_arrlen
** File description:
** my_arrlen
*/

#include "stddef.h"

int my_arrlen(char **arr)
{
    int count = 0;

    for (count = 0; arr[count] != NULL; count++);
    return (count);
}