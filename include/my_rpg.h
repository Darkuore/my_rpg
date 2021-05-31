/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** my_rpg
*/

#ifndef MY_RPG_H_
#define MY_RPG_H_

#include "my_include.h"
#include "param.h"
#include "mini_game.h"
#include "object.h"

/* function call just after the main to init everything */
int init_rpg(void);

/* add pos of all sprite to configure the map */
void make_map(char **map, object_t **obj);

/* draw one object */
void one_sprite_draw(sfRenderWindow *window, object_t *obj);
/* draw all sprite of a object** struct */
void sprite_draw(sfRenderWindow *window, object_t **obj);

/* compare the pos of the mouse with a sprite */
int gest_mouse(param_t *param, object_t **main_menu, int sprite_start);

/* main_menu function */
int main_menu(param_t *param, all_obj_t *all_obj);
/* main_menu event */
int menu_event(param_t *param, all_obj_t *all_obj);

/* custom map function */
void custom_map(param_t *param, all_obj_t *all_obj);
/* custom map event */
int custom_event(param_t *param, all_obj_t *all_obj, int *key, int *status);
/* custom map gest the sprite selected */
int custom_sprite(param_t *param, object_t **cust, int sprite_cd);

/* gameplay function */
void gameplay(param_t *param, all_obj_t *all_obj);
/* gameplay event with gestion of player mouvement */
int event_motion(param_t *param, all_obj_t *all_obj, int sprite);
/* motion of the player */
int motion(param_t *param, object_t **perso, int status);
/* do the animation of the player */
void do_animation(param_t *param, object_t **perso, int save);
/* init view for gameplay */
void init_view(object_t **perso, param_t *param, int save);

/* game_menu function */
int game_menu(param_t *param, all_obj_t *all_obj);

/* setting menu function */
int setting_menu(param_t *param, all_obj_t *all_obj, int status);
/* setting menu event */
int setting_event(param_t *param, all_obj_t *all_obj);

/* how to play function */
int how_to_play(param_t *param, all_obj_t *all_obj);
/* how to play event */
int how_to_play_event(param_t *param);

void pnj_interaction(all_obj_t *all_obj, param_t *param, int save);
void fight_interaction(all_obj_t *all_obj, param_t *param, int save);

#endif /* !MY_RPG_H_ */