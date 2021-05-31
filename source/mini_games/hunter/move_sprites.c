/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-gurvan.le-letty
** File description:
** move_sprites
*/

#include "my_rpg.h"
#include <stdio.h>
#include <stdlib.h>

static int loop_sprites(param_t *param, object_t **mini_hunter, int sprite,
info_t *speed)
{
    if (mini_hunter[sprite]->pos->x >= 1550) {
        speed->values[sprite] -= 1;
        mini_hunter[sprite]->pos->x = 385;
        mini_hunter[sprite]->pos->y = rand() % 400 + 210;
    }
    if (click_duck(param, mini_hunter, sprite) == sprite) {
        speed->count[sprite] += 1;
        speed->values[sprite] += 1;
        mini_hunter[sprite]->pos->x = 385;
        mini_hunter[sprite]->pos->y = rand() % 400 + 210;
        speed->count[0] += 1;
    }
    return (0);
}

int move_sprites(param_t *param, object_t **mini_hunter, info_t *speed)
{
    for (int i = 2; i <= 5; i++) {
        mini_hunter[i]->pos[0].x += speed->values[i];
        loop_sprites(param, mini_hunter, i, speed);
    }
    if (mini_hunter[7]->pos->x >= 1530)
        mini_hunter[7]->pos->x = 385;
    mini_hunter[7]->pos->x += 0.5;
    return (0);
}