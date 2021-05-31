/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-gurvan.le-letty
** File description:
** init_view
*/

#include "my_rpg.h"
#include "my_include.h"

void init_view(object_t **perso, param_t *param, int save)
{
    sfFloatRect view_rect = {0, 0, 960, 540};
    sfVector2f center_player_cam = {45, 45};

    sfView_reset(param->view, view_rect);
    sfView_setCenter(param->view, sfSprite_getPosition(perso[save]->sprite));
    sfView_move(param->view, center_player_cam);
    sfRenderWindow_setView(param->window, param->view);
}