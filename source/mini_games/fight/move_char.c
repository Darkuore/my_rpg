/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-gurvan.le-letty
** File description:
** move_char
*/

#include "my_rpg.h"
#include <stdio.h>
#include <stdlib.h>

int move_char(all_obj_t *all_obj , mini_fight_t *fight, int *status)
{
    if (all_obj->mini_fight[3]->pos[0].x >= 1200 && status[1] == false)
        all_obj->mini_fight[3]->pos->x -= 1.5;
    if (all_obj->mini_fight[5]->pos[0].x <= 900 && status[1] == false)
        all_obj->mini_fight[5]->pos->x += 1.9;
    if (all_obj->mini_fight[3]->pos[0].x <= 1200 &&
    all_obj->mini_fight[4]->pos[0].x <= 690 && status[1] == false) {
        all_obj->mini_fight[4]->pos->x += 1.5;
        clock_marvin(all_obj, fight);
    }
    if (all_obj->mini_fight[4]->pos[0].x >= 690) {
        all_obj->mini_fight[8]->count_key = 1;
        status[1] = true;
    }
    return (0);
}