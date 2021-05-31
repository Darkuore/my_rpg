/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** create_object
*/

#include <stdlib.h>
#include "my.h"
#include "object.h"

static object_t *create_obj(char *info)
{
    object_t *obj = NULL;
    char **all_info = NULL;

    obj = malloc(sizeof(object_t));
    if (obj == NULL)
        return (NULL);
    all_info = make_info(info);
    if (all_info == NULL)
        return (NULL);
    obj->sprite = sfSprite_create();
    obj->text = sfTexture_createFromFile(all_info[0], NULL);
    obj->rect = set_rect(all_info[1]);
    obj->pos = set_vector(all_info[2], all_info[5]);
    obj->scale = set_vector(all_info[3], all_info[4]);
    obj->count_key = 1;
    free_arr(all_info);
    if (obj->rect.height == -1 || obj->scale == NULL || obj->pos == NULL)
        return (NULL);
    return (obj);
}

object_t **create_object(char const *confpath)
{
    object_t **object = NULL;
    char **file = NULL;
    int file_line = 0;

    file = set_file(confpath, '\n');
    if (file == NULL)
        return (NULL);
    file_line = my_arrlen(file);
    object = malloc(sizeof(object_t *) * (file_line + 1));
    if (object == NULL)
        return (NULL);
    object[file_line] = NULL;
    for (int i = 0; file[i] != NULL; i++) {
        object[i] = create_obj(file[i]);
        if (object[i] == NULL)
            return (NULL);
    }
    free_arr(file);
    return (object);
}