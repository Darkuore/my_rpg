/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-gurvan.le-letty
** File description:
** clock
*/

#include "my_rpg.h"

static void move(sfIntRect *rect, float offset, int max_value)
{
    rect->left = rect->left + offset;
    if (rect->left > max_value)
        rect->left = 0;
}

static void run_clock(param_t *param, object_t **perso, int save)
{
    if (param->clock[0]->second > 1000.00) {
        move(&perso[save]->rect, 64, 512);
        sfClock_restart(param->clock[0]->clock);
    }
}

void do_animation(param_t *param, object_t **perso, int save)
{
    param->clock[0]->time = sfClock_getElapsedTime(param->clock[0]->clock);
    param->clock[0]->second = param->clock[0]->time.microseconds / 100.0;
    if (param->status[0] == true)
        run_clock(param, perso, save);
    else
        perso[save]->rect.left = 0;
}