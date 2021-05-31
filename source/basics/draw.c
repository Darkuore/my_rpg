/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** draw
*/

#include <stddef.h>
#include "my_rpg.h"

void one_sprite_draw(sfRenderWindow *window, object_t *obj)
{
    sfSprite_setTexture(obj->sprite, obj->text, sfFalse);
    sfSprite_setScale(obj->sprite, obj->scale[0]);
    sfSprite_setTextureRect(obj->sprite, obj->rect);
    for (int i = 0; i != obj->count_key; i++) {
        sfSprite_setPosition(obj->sprite, obj->pos[i]);
        sfRenderWindow_drawSprite(window, obj->sprite, NULL);
    }
}

void sprite_draw(sfRenderWindow *window, object_t **obj)
{
    for (int i = 0; obj[i] != NULL; i++) {
        one_sprite_draw(window, obj[i]);
    }
}