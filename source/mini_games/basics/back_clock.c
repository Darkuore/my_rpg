/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** back_clock
*/

#include "my_rpg.h"

void back_clock(param_t *param, object_t **mini_game)
{
    param->clock[0]->time = sfClock_getElapsedTime(param->clock[0]->clock);
    param->clock[0]->second = sfTime_asSeconds(param->clock[0]->time);
    if (param->clock[0]->second > 0.100) {
        move_rect(&mini_game[0]->rect, 500, 8000);
        sfClock_restart(param->clock[0]->clock);
    }
}