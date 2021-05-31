/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-gurvan.le-letty
** File description:
** fight_interaction
*/

#include "my_include.h"
#include "my_rpg.h"

static int const FANTOM = 5;

void fight_interaction(all_obj_t *all_obj, param_t *param, int save)
{
    if (all_obj->perso[save]->pos[0].x >= all_obj->perso[FANTOM]->pos[0].x
    && all_obj->perso[save]->pos[0].x <= (all_obj->perso[FANTOM]->pos[0].x + 10)
    && all_obj->perso[save]->pos[0].y >= all_obj->perso[FANTOM]->pos[0].y
    && all_obj->perso[save]->pos[0].y <=
    (all_obj->perso[FANTOM]->pos[0].y + 10)) {
        if (param->status[2] == false) {
            sfRenderWindow_setView(param->window,
                    sfRenderWindow_getDefaultView(param->window));
            mini_fight(param, all_obj);
            param->status[2] = true;
            param->status[0] = false;
            sfRenderWindow_clear(param->window, sfBlack);
        }
    }
}