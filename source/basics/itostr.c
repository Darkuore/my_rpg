/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-gurvan.le-letty
** File description:
** text_tools
*/

#include <stdlib.h>
#include "my.h"

static char const base[11] = "0123456789";

char *itostr(int nb)
{
    char *score = malloc(sizeof(char) * 20);
    int i = 0;
    int buff = 0;

    while (nb > 9) {
        buff = nb % 10;
        score[i] = base[buff];
        i++;
        nb = nb / 10;
    }
    buff = nb % 10;
    score[i] = base[buff];
    score[i + 1] = '\0';
    my_revstr(score);
    return (score);
}