/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-gurvan.le-letty
** File description:
** motion
*/

#include "my_rpg.h"

static bool check_valid_motion(char **map, int x, int y)
{
    if (map[y][x] != '3' && map[y][x] != '9' && map[y][x] != '7'
        && map[y][x] != '2' && map[y][x] != '8' && map[y][x] != '=')
        return (true);
    return (false);
}

static void change_position(object_t **perso, int x, int y)
{
    for (int i = 0; i < 4; i++) {
        perso[i]->pos[0].x = x;
        perso[i]->pos[0].y = y;
    }
}

static int move_horiz(param_t *param, object_t **perso, int sprite)
{
    int x = (perso[sprite]->pos[0].x + 48) / 48;
    int y = (perso[sprite]->pos[0].y + 48) / 48;

    if (sfKeyboard_isKeyPressed(sfKeyRight) == true
        && check_valid_motion(param->map, x + 1, y) == true) {
        sprite = 3;
        param->status[0] = true;
        if (perso[sprite]->pos->x < 1870)
            perso[sprite]->pos->x += 2;
        change_position(perso, perso[sprite]->pos->x, perso[sprite]->pos->y);
    }
    if (sfKeyboard_isKeyPressed(sfKeyLeft) == true
        && check_valid_motion(param->map, x - 1, y) == true) {
        sprite = 1;
        param->status[0] = true;
        if (perso[sprite]->pos->x > 0)
            perso[sprite]->pos->x -= 2;
        change_position(perso, perso[sprite]->pos->x, perso[sprite]->pos->y);
    }
    return (sprite);
}

static int move_vert(param_t *param, object_t **perso, int sprite)
{
    int x = (perso[sprite]->pos[0].x + 48) / 48;
    int y = (perso[sprite]->pos[0].y + 48) / 48;

    if (sfKeyboard_isKeyPressed(sfKeyUp) == true
        && check_valid_motion(param->map, x, y - 1) == true) {
        sprite = 0;
        param->status[0] = true;
        if (perso[sprite]->pos->y > 0)
            perso[sprite]->pos->y -= 2;
        change_position(perso, perso[sprite]->pos->x, perso[sprite]->pos->y);
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown) == true
        && check_valid_motion(param->map, x, y - 1) == true) {
        sprite = 2;
        param->status[0] = true;
        if (perso[sprite]->pos->y < 1080)
            perso[sprite]->pos->y += 2;
        change_position(perso, perso[sprite]->pos->x, perso[sprite]->pos->y);
    }
    return (sprite);
}

int motion(param_t *param, object_t **perso, int sprite)
{
    sprite = move_horiz(param, perso, sprite);
    sprite = move_vert(param, perso, sprite);
    return (sprite);
}