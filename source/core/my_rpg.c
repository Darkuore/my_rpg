/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** my_rpg
*/

#include <stdlib.h>
#include "my_rpg.h"

static char const *MAP = "assets/map/map1";
char const *MUSIC = "sprites/shop.ogg";

static int launch_menu(param_t *param, all_obj_t *all_obj, int status)
{
    if (status == 1)
        gameplay(param, all_obj);
    if (status == 2)
        custom_map(param, all_obj);
    return (0);
}

static int my_rpg(param_t *param, all_obj_t *all_obj)
{
    int status = 0;

    sfRenderWindow_setFramerateLimit(param->window, param->framerate);
    sfMusic_play(param->music);
    while (sfRenderWindow_isOpen(param->window)) {
        status = main_menu(param, all_obj);
        launch_menu(param, all_obj, status);
    }
    return (0);
}

int init_rpg(void)
{
    param_t *param = NULL;
    all_obj_t *all_obj = NULL;

    srand(time(NULL));
    param = create_param(MAP, MUSIC);
    if (param == NULL)
        return (84);
    all_obj = create_all_obj();
    if (all_obj == NULL)
        return (84);
    make_map(param->map, all_obj->map);
    my_rpg(param, all_obj);
    destroy_all_obj(all_obj);
    destroy_param(param);
    return (0);
}