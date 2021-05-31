/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** gest_mous
*/

#include "my_rpg.h"

int gest_mouse(param_t *param, object_t **main_menu, int sprite_start)
{
    param->mouse_coord = sfMouse_getPositionRenderWindow(param->window);
    for (int i = sprite_start; main_menu[i] != NULL; i++)
        if (param->mouse_coord.x >= main_menu[i]->pos->x
        && param->mouse_coord.x <= (main_menu[i]->pos->x +
        (main_menu[i]->rect.width * main_menu[i]->scale->x))
        && param->mouse_coord.y >= main_menu[i]->pos->y &&
        param->mouse_coord.y <= (main_menu[i]->pos->y +
        (main_menu[i]->rect.height * main_menu[i]->scale->y)))
            return (i);
    return (0);
}