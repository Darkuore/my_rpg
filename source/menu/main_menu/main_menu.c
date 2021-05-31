/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** main_menu
*/

#include "my_rpg.h"

int main_menu(param_t *param, all_obj_t *all_obj)
{
    int event_info = 0;

    while (sfRenderWindow_isOpen(param->window)) {
        event_info = menu_event(param, all_obj);
        if (event_info != 0)
            break;
        sprite_draw(param->window, all_obj->main_menu);
        sfRenderWindow_display(param->window);
    }
    sfRenderWindow_clear(param->window, sfBlack);
    return (event_info);
}