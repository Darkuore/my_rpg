/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-gurvan.le-letty
** File description:
** pnj_interaction
*/

#include "my_include.h"
#include "my_rpg.h"

static int const CHAMAN = 4;
static char const *speaker = "I need 30 ducks, can you help me ?\nPress enter";

static bool discussion(all_obj_t *all_obj, param_t *param)
{
    one_sprite_draw(param->window, all_obj->perso[6]);
    sfText_setString(all_obj->texts[7]->text, speaker);
    sfRenderWindow_drawText(param->window, all_obj->texts[7]->text, NULL);
    if (sfKeyboard_isKeyPressed(sfKeyReturn) == true)
        return (true);
    return (false);
}

void pnj_interaction(all_obj_t *all_obj, param_t *param, int save)
{
    bool pass = false;

    if (all_obj->perso[save]->pos[0].x >= all_obj->perso[CHAMAN]->pos[0].x
    && all_obj->perso[save]->pos[0].x <= (all_obj->perso[CHAMAN]->pos[0].x + 10)
    && all_obj->perso[save]->pos[0].y >= all_obj->perso[CHAMAN]->pos[0].y
    && all_obj->perso[save]->pos[0].y <=
    (all_obj->perso[CHAMAN]->pos[0].y + 10)) {
        pass = discussion(all_obj, param);
        if (param->status[1] == false && pass == true) {
            sfRenderWindow_setView(param->window,
                sfRenderWindow_getDefaultView(param->window));
            mini_hunter(param, all_obj);
            param->status[1] = true;
            param->status[0] = false;
            sfRenderWindow_clear(param->window, sfBlack);
        }
    }
}