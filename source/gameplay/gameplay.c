/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-gurvan.le-letty
** File description:
** gameplay
*/

#include <stdio.h>
#include "my_rpg.h"

static int const CHAMAN = 4;
static int const FANTOM = 5;

static void draw_all_character(object_t **perso, param_t *param, int save)
{
    one_sprite_draw(param->window, perso[CHAMAN]);
    one_sprite_draw(param->window, perso[FANTOM]);
    one_sprite_draw(param->window, perso[save]);
}

void gameplay(param_t *param, all_obj_t *all_obj)
{
    int sprite = 3, save = 3;

    while (sfRenderWindow_isOpen(param->window)) {
        init_view(all_obj->perso, param, save);
        sprite = event_motion(param, all_obj, save);
        if (sprite == -2)
            break;
        if (sprite >= 0)
            save = sprite;
        do_animation(param, all_obj->perso, save);
        sprite_draw(param->window, all_obj->map);
        draw_all_character(all_obj->perso, param, save);
        pnj_interaction(all_obj, param, save);
        fight_interaction(all_obj, param, save);
        sfRenderWindow_display(param->window);
        sfRenderWindow_clear(param->window, sfBlack);
    }
}