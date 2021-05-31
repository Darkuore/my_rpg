/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-gurvan.le-letty
** File description:
** click_duck
*/

#include "my_rpg.h"
#include <stdio.h>
#include <stdlib.h>

int click_duck(param_t *param, object_t **mini_hunter, int sprite)
{
    sfVector2i mouseclick = sfMouse_getPositionRenderWindow(param->window);
    sfVector2f duck = sfSprite_getPosition(mini_hunter[sprite]->sprite);

    if (param->event.type == sfEvtMouseButtonPressed) {
        if (mouseclick.x > duck.x - 30 && mouseclick.y > duck.y &&
            mouseclick.x < duck.x + 50 && mouseclick.y < duck.y + 50) {
            return (sprite);
        }
    }
    return (0);
}