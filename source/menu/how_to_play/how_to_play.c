/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** how_to_play
*/

#include "my_rpg.h"

int how_to_play(param_t *param, all_obj_t *all_obj)
{
    sfRenderWindow_clear(param->window, sfBlack);
    while (sfRenderWindow_isOpen(param->window)) {
        sprite_draw(param->window, all_obj->how_to_play);
        if (how_to_play_event(param) == -1)
            break;
        sfRenderWindow_display(param->window);
    }
    return (0);
}