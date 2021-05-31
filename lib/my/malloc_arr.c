/*
** EPITECH PROJECT, 2021
** malloc_arr.c
** File description:
** malloc_arr
*/

#include <stdlib.h>

char **malloc_arr(int lines, int cols)
{
    char **arr = NULL;

    arr = malloc(sizeof(char *) * (lines + 1));
    if (arr == NULL)
        return (NULL);
    arr[lines] = NULL;
    for (int i = 0; arr[i] != NULL; i++) {
        arr[i] = malloc(sizeof(char) * (cols + 1));
        if (arr[i] == NULL)
            return (NULL);
        arr[i][cols] = '\0';
    }
    return (arr);
}