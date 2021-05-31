/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-gurvan.le-letty
** File description:
** how_to_play_event
*/

#include "param.h"

static int event_key_pressed(param_t *param)
{
    if (param->event.key.code == sfKeyEscape)
        return (-1);
    return (0);
}

int how_to_play_event(param_t *param)
{
    while (sfRenderWindow_pollEvent(param->window, &param->event)) {
        if (param->event.type == sfEvtClosed)
            sfRenderWindow_close(param->window);
        if (param->event.type == sfEvtKeyPressed)
            return (event_key_pressed(param));
    }
    return (0);
}