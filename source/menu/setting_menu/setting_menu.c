/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** setting_menu
*/

#include <stdio.h>
#include "my_rpg.h"

enum PLACE {MENU = 1, GAME};

int setting_menu(param_t *param, all_obj_t *all_obj, int status)
{
    sfRenderWindow_clear(param->window, sfBlack);
    while (sfRenderWindow_isOpen(param->window)) {
        if (status == MENU)
            sprite_draw(param->window, all_obj->main_menu);
        if (status == GAME) {
            sprite_draw(param->window, all_obj->map);
            sprite_draw(param->window, all_obj->perso);
            sprite_draw(param->window, all_obj->game_menu);
        }
        sprite_draw(param->window, all_obj->setting_menu);
        if (setting_event(param, all_obj) == -1)
            break;
        sfRenderWindow_display(param->window);
    }
    return (0);
}