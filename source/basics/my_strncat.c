/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-gurvan.le-letty
** File description:
** my_strncat
*/

#include <stdlib.h>
#include "my.h"

char *my_strncat(char *dest, char *src)
{
    int i = 0, count = 0;
    int length = my_strlen(dest) + my_strlen(src);
    char *res = malloc(sizeof(char) * (length + 1));

    for (i = 0; (res[i] = dest[i]); i++);
    while (src[count]) {
        res[i + count] = src[count];
        count++;
    }
    res[i + count] = '\0';
    return (res);
}