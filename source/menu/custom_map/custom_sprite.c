/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** custom_sprite
*/

#include "my_rpg.h"

enum cust_sprite { ROAD = 1, TREE, WATER};

static int const SPRITE_ROAD[] = {14, 15, 16, 17, 18, 19, 20, 21,
    22, 23, 24, 25, 26, 27, 28, 29};
static int const SPRITE_WATER[] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
static int const SPRITE_TREE[] = {2, 3};

int custom_sprite(param_t *param, object_t **cust, int sprite_cd)
{
    int key = 0;

    sprite_draw(param->window, cust);
    key = gest_mouse(param, cust, 1);
    if (key == 0)
        return (0);
    switch (sprite_cd) {
        case ROAD:
            key = SPRITE_ROAD[key - 1];
            break;
        case WATER:
            key = SPRITE_WATER[key - 1];
            break;
        case TREE:
            key = SPRITE_TREE[key - 1];
            break;
    }
    return (key);
}