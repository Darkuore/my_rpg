/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** custom_event
*/

#include "my_rpg.h"

static void gest_button(int *key, int *status)
{
    if (key[0] <= 5 && key[0] > 0)
        status[key[0] - 1] += 1;
    for (int i = 0; i != 5; i++)
        status[i] = status[i] % 2;
}

static int event_key_pressed(param_t *param)
{
    if (param->event.key.code == sfKeyEscape)
        return (-1);
    return (0);
}

int custom_event(param_t *param, all_obj_t *all_obj, int *key, int *status)
{
    key[0] = gest_mouse(param, all_obj->cust_map, 1);
    while (sfRenderWindow_pollEvent(param->window, &param->event)) {
        if (param->event.type == sfEvtClosed)
            sfRenderWindow_close(param->window);
        if (param->event.type == sfEvtKeyPressed)
            return (event_key_pressed(param));
        if (param->event.type == sfEvtMouseButtonPressed)
            gest_button(key, status);
    }
    return (0);
}