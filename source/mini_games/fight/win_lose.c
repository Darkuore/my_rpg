/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-gurvan.le-letty
** File description:
** win_lose
*/

#include "my_rpg.h"
#include <stdio.h>
#include <stdlib.h>

void win_lose(all_obj_t *all_obj, mini_fight_t *fight, int *status)
{
    if (fight->pv[1] == 0)
        win(all_obj, status);
    if (fight->pv[0] == 0)
        lose(all_obj, status);
}

void win(all_obj_t *all_obj, int *status)
{
    status[1] = false;
    status[2] = false;
    end(all_obj);
    all_obj->mini_fight[14]->count_key = 1;
    all_obj->mini_fight[17]->count_key = 1;

}

void lose(all_obj_t *all_obj, int *status)
{
    status[1] = false;
    end(all_obj);
    all_obj->mini_fight[15]->count_key = 1;
    all_obj->mini_fight[18]->count_key = 1;

}

void end(all_obj_t *all_obj)
{
    all_obj->mini_fight[8]->count_key = 0;
    all_obj->mini_fight[11]->count_key = 0;
    all_obj->mini_fight[12]->count_key = 0;
    all_obj->mini_fight[13]->count_key = 0;
}