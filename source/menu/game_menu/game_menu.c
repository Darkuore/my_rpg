/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** game_menu
*/

#include "my_rpg.h"

static void scale_button(object_t **menu, int key)
{
    for (int i = 1; menu[i] != NULL; i++) {
        if (key == i) {
            menu[i]->scale[0] = menu[i]->scale[2];
            menu[i]->pos[0] = menu[i]->pos[2];
        }
        else {
            menu[i]->scale[0] = menu[i]->scale[1];
            menu[i]->pos[0] = menu[i]->pos[1];
        }
    }
}

static int gest_button(param_t *param, all_obj_t *all_obj, int key)
{
    if (key == 1 || key == 2)
        return (key * (-1));
    if (key == 3)
        sfRenderWindow_close(param->window);
    if (key == 4)
        return (setting_menu(param, all_obj, 2));
    return (key);

}

static int event_key_pressed(param_t *param)
{
    if (param->event.key.code == sfKeyEscape)
        return (-1);
    return (0);
}

int game_menu_event(param_t *param, all_obj_t *all_obj)
{
    int key = 0;

    key = gest_mouse(param, all_obj->game_menu, 1);
    scale_button(all_obj->game_menu, key);
    while (sfRenderWindow_pollEvent(param->window, &param->event)) {
        if (param->event.type == sfEvtClosed)
            sfRenderWindow_close(param->window);
        if (param->event.type == sfEvtKeyPressed)
            return (event_key_pressed(param));
        if (param->event.type == sfEvtMouseButtonPressed)
            return (gest_button(param, all_obj, key));
    }
    return (0);
}

int game_menu(param_t *param, all_obj_t *all_obj)
{
    int event_info = 0;

    while (sfRenderWindow_isOpen(param->window)) {
        event_info = game_menu_event(param, all_obj);
        if (event_info != 0)
            break;
        sprite_draw(param->window, all_obj->map);
        sprite_draw(param->window, all_obj->perso);
        sprite_draw(param->window, all_obj->game_menu);
        sfRenderWindow_display(param->window);
    }
    sfRenderWindow_clear(param->window, sfBlack);
    return (event_info);
}