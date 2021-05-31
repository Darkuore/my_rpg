/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** gameplay_event
*/

#include "my_rpg.h"

int event_motion(param_t *param, all_obj_t *all_obj, int sprite)
{
    sprite = motion(param, all_obj->perso, sprite);
    while (sfRenderWindow_pollEvent(param->window, &param->event)) {
        if (param->event.type == sfEvtClosed)
            sfRenderWindow_close(param->window);
        if (param->event.type == sfEvtKeyPressed)
            if (param->event.key.code == sfKeyEscape) {
                sfRenderWindow_setView(param->window,
                    sfRenderWindow_getDefaultView(param->window));
                return (game_menu(param, all_obj));
            }
        if (param->event.type == sfEvtKeyReleased)
            param->status[0] = false;
    }
    return (sprite);
}