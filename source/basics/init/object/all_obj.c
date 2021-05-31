/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** all_obj
*/

#include <stdlib.h>
#include "object.h"

static char const *MAIN_MENU = "assets/sprite/main_menu.conf";
static char const *GAME_MENU = "assets/sprite/game_menu.conf";
static char const *MAP = "assets/sprite/map.conf";
static char const *CUST_MAP = "assets/sprite/custom_map.conf";
static char const *HUNTER = "assets/sprite/mini_hunter.conf";
static char const *PERSO = "assets/sprite/charact.conf";
static char const *FIGHT = "assets/sprite/mini_fight.conf";
static char const *SETTING_MENU = "assets/sprite/setting_menu.conf";
static char const *HOW_TO_PLAY = "assets/sprite/how_to_play.conf";

static void fill_all_obj(all_obj_t *all_obj)
{
    all_obj->main_menu = create_object(MAIN_MENU);
    all_obj->map = create_object(MAP);
    all_obj->cust_map = create_object(CUST_MAP);
    all_obj->cust_struct = create_cust_struct();
    all_obj->mini_hunter = create_object(HUNTER);
    all_obj->mini_fight = create_object(FIGHT);
    all_obj->perso = create_object(PERSO);
    all_obj->game_menu = create_object(GAME_MENU);
    all_obj->setting_menu = create_object(SETTING_MENU);
    all_obj->how_to_play = create_object(HOW_TO_PLAY);
}

all_obj_t *create_all_obj(void)
{
    all_obj_t *all_obj = NULL;

    all_obj = malloc(sizeof(all_obj_t));
    if (all_obj == NULL)
        return (NULL);
    fill_all_obj(all_obj);
    all_obj->texts = handle_text();
    if (all_obj->main_menu == NULL || all_obj->map == NULL
    || all_obj->cust_map == NULL || all_obj->cust_struct == NULL
    || all_obj->mini_hunter == NULL || all_obj->perso == NULL
    || all_obj->game_menu == NULL || all_obj->mini_fight == NULL
    || all_obj->setting_menu == NULL || all_obj->texts == NULL)
        return (NULL);
    return (all_obj);
}

static void destroy_text(text_t **texts)
{
    for (int i = 0; texts[i] != NULL; i++) {
        sfText_destroy (texts[i]->text);
        sfFont_destroy (texts[i]->font);
        free(texts[i]);
    }
    free(texts);
}

void destroy_all_obj(all_obj_t *all_obj)
{
    destroy_obj(all_obj->main_menu);
    destroy_obj(all_obj->map);
    destroy_obj(all_obj->cust_map);
    destroy_cust_struct(all_obj->cust_struct);
    destroy_obj(all_obj->mini_hunter);
    destroy_obj(all_obj->mini_fight);
    destroy_obj(all_obj->perso);
    destroy_obj(all_obj->game_menu);
    destroy_obj(all_obj->setting_menu);
    destroy_obj(all_obj->how_to_play);
    destroy_text(all_obj->texts);
    free(all_obj);
}