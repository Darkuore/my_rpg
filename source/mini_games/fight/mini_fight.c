/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-gurvan.le-letty
** File description:
** mini-hunter
*/

#include <stdlib.h>
#include "my_rpg.h"

static void cursor(param_t *param, all_obj_t *all_obj)
{
    param->mouse_coord = sfMouse_getPositionRenderWindow(param->window);
    all_obj->mini_fight[19]->pos[0].x = param->mouse_coord.x - 26;
    all_obj->mini_fight[19]->pos[0].y = param->mouse_coord.y - 24;
}

int mini_fight(param_t *param, all_obj_t *all_obj)
{
    int status[] = {false, false, false};
    mini_fight_t *fight = create_fight();

    draw_later(all_obj);
    sfRenderWindow_clear(param->window, sfBlack);
    sfRenderWindow_setMouseCursorVisible(param->window, sfFalse);
    while (sfRenderWindow_isOpen(param->window)) {
        cursor(param, all_obj);
        analyse_events(param);
        sprite_draw(param->window, all_obj->mini_fight);
        print_texts_fight(param->window, all_obj->texts, fight);
        move_char(all_obj, fight, status);
        choose_fight(param, all_obj, fight, status);
        back_clock(param, all_obj->mini_fight);
        clock_ennemi(param, all_obj);
        win_lose(all_obj, fight, status);
        sfRenderWindow_display(param->window);
    }
    free(fight);
    return (0);
}

void draw_later(all_obj_t *all_obj)
{
    all_obj->mini_fight[8]->count_key = 0;
    all_obj->mini_fight[11]->count_key = 0;
    all_obj->mini_fight[12]->count_key = 0;
    all_obj->mini_fight[13]->count_key = 0;
    all_obj->mini_fight[14]->count_key = 0;
    all_obj->mini_fight[15]->count_key = 0;
    all_obj->mini_fight[17]->count_key = 0;
    all_obj->mini_fight[18]->count_key = 0;
}