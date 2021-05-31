/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** custom_map
*/

#include "my_rpg.h"

enum cust_sprite { ROAD = 1, TREE, WATER};

static int cust_inter(param_t *param, all_obj_t *all_obj, int *status)
{
    int key = 0;

    sprite_draw(param->window, all_obj->cust_map);
    if (status[0] == 1 && status[1] == 1)
        key = custom_sprite(param, all_obj->cust_struct->cust_road, ROAD);
    if (status[0] == 1 && status[2] == 1)
        key = custom_sprite(param, all_obj->cust_struct->cust_tree, TREE);
    if (status[0] == 1 && status[3] == 1)
        key = custom_sprite(param, all_obj->cust_struct->cust_water, WATER);
    return (key);
}

void custom_map(param_t *param, all_obj_t *all_obj)
{
    int status[4] = {0, 0, 0, 0};
    int key[2] = {0, 0};

    while (sfRenderWindow_isOpen(param->window)) {
        if (custom_event(param, all_obj, key, status) == -1)
            break;
        sprite_draw(param->window, all_obj->map);
        if (status[0] == 0)
            one_sprite_draw(param->window, all_obj->cust_map[1]);
        else
            key[1] = cust_inter(param, all_obj, status);
        sfRenderWindow_display(param->window);
    }
}