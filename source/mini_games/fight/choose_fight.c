/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-gurvan.le-letty
** File description:
** choose_fight
*/

#include "my_rpg.h"
#include <stdio.h>
#include <stdlib.h>

int choose_fight(param_t *param, all_obj_t *all_obj, mini_fight_t *fight,
int *status)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(param->window);
    sfVector2f attack = sfSprite_getPosition(all_obj->mini_fight[9]->sprite);
    sfVector2f soigne = sfSprite_getPosition(all_obj->mini_fight[10]->sprite);

    if (mouse.x > attack.x && mouse.y > attack.y &&
    mouse.x < attack.x + 183 && mouse.y < attack.y + 58 && status[1] == true) {
        all_obj->mini_fight[8]->pos[0] = attack;
        attaquer(param, all_obj, fight, status);
    }
    if (mouse.x > soigne.x && mouse.y > soigne.y &&
    mouse.x < soigne.x + 183 && mouse.y < soigne.y + 58 && status[1] == true) {
        all_obj->mini_fight[8]->pos[0] = soigne;
        defendre(param, all_obj, fight, status);
    }
    return (0);
}

int attaquer(param_t *param, all_obj_t *all_obj, mini_fight_t *fight,
int *status)
{
    if (param->event.type == sfEvtMouseButtonPressed && status[0] == false) {
        all_obj->mini_fight[3]->pos[0].x = 1200;
        status[0] = true;
        all_obj->mini_fight[11]->count_key = 1;
        all_obj->mini_fight[13]->count_key = 0;
        fight->pv[1] -= 50;
        all_obj->mini_fight[4]->pos->x += 20;
        sfClock_restart(fight->clock_fantom);
        status[2] = true;
    }
    if (status[2] == true) {
        clock_fantom(all_obj, fight, status, 11);
    }

    return (0);
}

int clock_fantom(all_obj_t *all_obj, mini_fight_t *fight, int *status, int a)
{
    fight->time_fantom = sfClock_getElapsedTime(fight->clock_fantom);
    fight->second_fantom = sfTime_asSeconds(fight->time_fantom);
    if (fight->second_fantom > 2) {
        all_obj->mini_fight[4]->pos[0].x = 690;
        all_obj->mini_fight[a]->count_key = 0;
        status[2] = false;
        all_obj->mini_fight[13]->count_key = 1;
        all_obj->mini_fight[3]->pos[0].x -= 20;
        fight->pv[0] -= 40;
        status[0] = false;
        return (1);
    }
    return (0);
}

int defendre(param_t *param, all_obj_t *all_obj, mini_fight_t *fight,
int *status)
{
    if (param->event.type == sfEvtMouseButtonPressed && status[0] == false) {
        all_obj->mini_fight[13]->count_key = 0;
        all_obj->mini_fight[3]->pos[0].x = 1200;
        status[0] = true;
        all_obj->mini_fight[12]->count_key = 1;
        fight->pv[0] += 30;
        sfClock_restart(fight->clock_fantom);
        status[2] = true;
    }
    if (status[2] == true) {
        clock_fantom(all_obj, fight, status, 12);
    }
    return (0);
}