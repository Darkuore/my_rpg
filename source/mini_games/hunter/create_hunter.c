/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-gurvan.le-letty
** File description:
** create_hunter
*/

#include <stdlib.h>
#include "my_rpg.h"

info_t *speeds_sets(void)
{
    info_t *speed = NULL;

    speed = malloc(sizeof(info_t));
    if (speed == NULL)
        return (NULL);
    speed->values = malloc(sizeof(int) * 6);
    speed->count = malloc(sizeof(int) * 6);
    if (speed->count == NULL || speed->values == NULL)
        return (NULL);
    speed->values[0] = 0;
    speed->values[1] = 0;
    speed->values[2] = 3;
    speed->values[3] = 4;
    speed->values[4] = 3;
    speed->values[5] = 2;
    for (int i = 0; i != 6; i++)
        speed->count[i] = 0;
    return (speed);
}

void free_speed(info_t *speed)
{
    free(speed->values);
    free(speed->count);
    free(speed);
}