/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** destroy_obj
*/

#include <stdlib.h>
#include "object.h"

static void destroy_object(object_t *obj)
{
    sfSprite_destroy(obj->sprite);
    sfTexture_destroy(obj->text);
    free(obj->pos);
    free(obj->scale);
    free(obj);
}

void destroy_obj(object_t **obj)
{
    for (int i = 0; obj[i] != NULL; i++)
        destroy_object(obj[i]);
    free(obj);
}