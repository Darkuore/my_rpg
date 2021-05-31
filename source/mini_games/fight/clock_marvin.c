/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-gurvan.le-letty
** File description:
** clock_marvin
*/

#include "my_rpg.h"
#include <stdio.h>
#include <stdlib.h>

void clock_marvin(all_obj_t *all_obj, mini_fight_t *fight)
{
    fight->time_marvin = sfClock_getElapsedTime(fight->clock_marvin);
    fight->second_marvin = sfTime_asSeconds(fight->time_marvin);
    if (fight->second_marvin > 0.140) {
        move_rect(&all_obj->mini_fight[4]->rect, 64, 512);
        sfClock_restart(fight->clock_marvin);
    }
}