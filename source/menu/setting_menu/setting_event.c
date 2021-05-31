/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** setting_event
*/

#include "my_rpg.h"

static void scale_button(object_t **setting, int key)
{
    for (int i = 1; setting[i] != NULL; i++) {
        if (key == i) {
            setting[i]->scale[0] = setting[i]->scale[2];
            setting[i]->pos[0] = setting[i]->pos[2];
        }
        else {
            setting[i]->scale[0] = setting[i]->scale[1];
            setting[i]->pos[0] = setting[i]->pos[1];
        }
    }
}

static int gest_button(param_t *param, int key)
{
    if (key == 3)
        param->volume -= 10;
    if (key == 4)
        param->volume += 10;
    if (key == 5)
        param->framerate -= 10;
    if (key == 6)
        param->framerate += 10;
    sfRenderWindow_setFramerateLimit(param->window, param->framerate);
    sfMusic_setVolume(param->music, param->volume);
    return (key);

}

static int event_key_pressed(param_t *param)
{
    if (param->event.key.code == sfKeyEscape)
        return (-1);
    return (0);
}

int setting_event(param_t *param, all_obj_t *all_obj)
{
    int key = 0;

    key = gest_mouse(param, all_obj->setting_menu, 3);
    scale_button(all_obj->setting_menu, key);
    while (sfRenderWindow_pollEvent(param->window, &param->event)) {
        if (param->event.type == sfEvtClosed)
            sfRenderWindow_close(param->window);
        if (param->event.type == sfEvtKeyPressed)
            return (event_key_pressed(param));
        if (param->event.type == sfEvtMouseButtonPressed)
            return (gest_button(param, key));
    }
    return (0);
}