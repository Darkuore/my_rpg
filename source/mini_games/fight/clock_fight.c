/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-gurvan.le-letty
** File description:
** clock_fight
*/

#include "my_rpg.h"
#include <stdio.h>
#include <stdlib.h>

void clock_ennemi(param_t *param, all_obj_t *all_obj)
{
    param->clock[1]->time = sfClock_getElapsedTime(param->clock[1]->clock);
    param->clock[1]->second = sfTime_asSeconds(param->clock[1]->time);
    if (param->clock[1]->second > 0.20) {
        move_rect(&all_obj->mini_fight[3]->rect, 48, 144);
        sfClock_restart(param->clock[1]->clock);
    }
}