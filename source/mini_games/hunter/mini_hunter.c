/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-gurvan.le-letty
** File description:
** mini-hunter
*/

#include <stdlib.h>
#include "my_rpg.h"

static void crosshair(param_t *param, all_obj_t *all_obj)
{
    param->mouse_coord = sfMouse_getPositionRenderWindow(param->window);
    all_obj->mini_hunter[14]->pos[0].x = param->mouse_coord.x - 26;
    all_obj->mini_hunter[14]->pos[0].y = param->mouse_coord.y - 24;
}

int mini_hunter(param_t *param, all_obj_t *all_obj)
{
    info_t *speed = speeds_sets();

    sfRenderWindow_clear(param->window, sfBlack);
    sfRenderWindow_setMouseCursorVisible(param->window, sfFalse);
    while (sfRenderWindow_isOpen(param->window)) {
        crosshair(param, all_obj);
        if (analyse_events(param) == -1)
            break;
        move_sprites(param, all_obj->mini_hunter, speed);
        back_clock(param, all_obj->mini_hunter);
        clock_duck(param, all_obj);
        sprite_draw(param->window, all_obj->mini_hunter);
        print_texts(param->window, all_obj->texts, speed);
        sfRenderWindow_display(param->window);
        if (analyse_mission(speed) == 1)
            break;
    }
    sfRenderWindow_setMouseCursorVisible(param->window, sfTrue);
    free_speed(speed);
    return (0);
}