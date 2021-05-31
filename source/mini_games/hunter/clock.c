/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-gurvan.le-letty
** File description:
** clock
*/

#include "my_rpg.h"

void clock_duck(param_t *param, all_obj_t *all_obj)
{
    param->clock[1]->time = sfClock_getElapsedTime(param->clock[1]->clock);
    param->clock[1]->second = sfTime_asSeconds(param->clock[1]->time);
    if (param->clock[1]->second > 0.100) {
        move_rect(&all_obj->mini_hunter[2]->rect, 110, 330);
        move_rect(&all_obj->mini_hunter[3]->rect, 110, 330);
        move_rect(&all_obj->mini_hunter[4]->rect, 110, 330);
        move_rect(&all_obj->mini_hunter[5]->rect, 110, 330);
        move_rect(&all_obj->mini_hunter[7]->rect, 60, 300);
        sfClock_restart(param->clock[1]->clock);
    }
}