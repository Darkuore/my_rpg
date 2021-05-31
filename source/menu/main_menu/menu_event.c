/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** event
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
    if (key == 3)
        sfRenderWindow_close(param->window);
    if (key == 4)
        return (setting_menu(param, all_obj, 1));
    if (key == 5)
        return (how_to_play(param, all_obj));
    return (key);

}

static void event_key_pressed(param_t *param)
{
    if (param->event.key.code == sfKeyEscape)
        sfRenderWindow_close(param->window);
}

int menu_event(param_t *param, all_obj_t *all_obj)
{
    int key = 0;

    key = gest_mouse(param, all_obj->main_menu, 1);
    scale_button(all_obj->main_menu, key);
    while (sfRenderWindow_pollEvent(param->window, &param->event)) {
        if (param->event.type == sfEvtClosed)
            sfRenderWindow_close(param->window);
        if (param->event.type == sfEvtKeyPressed)
            event_key_pressed(param);
        if (param->event.type == sfEvtMouseButtonPressed)
            return (gest_button(param, all_obj, key));
    }
    return (0);
}