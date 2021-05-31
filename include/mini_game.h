/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** mini_game
*/

#ifndef MINI_GAME_H_
#define MINI_GAME_H_

#include "object.h"
#include "param.h"

/* info struct for mini_hunter game with count && values for birds */
typedef struct info_s
{
    int *count;
    int *values;
} info_t;

typedef struct mini_fight_s
{
    sfEvent event;
    sfClock *clock_marvin;
    sfClock *clock_fantom;
    sfTime time_marvin;
    sfTime time_fantom;
    float second_marvin;
    float second_fantom;
    int *pv;
}mini_fight_t;

/* event for mini_games basic (close window && come back with escape key) */
int analyse_events(param_t *param);

/* gestion of the clock for the back ground of all mini games */
void back_clock(param_t *param, object_t **mini_game);

/* moove_rect to create a mouvement with the sprite  */
void move_rect(sfIntRect *rect, int offset, int max_value);

/* create the info struct with speed && score of each duck */
info_t *speeds_sets(void);
/* free info struct of speed */
void free_speed(info_t *speed);

/* mini hunter game */
int mini_hunter(param_t *param, all_obj_t *all_obj);
/* gestion of the duck_clock */
void clock_duck(param_t *param, all_obj_t *all_obj);
/* gestion when we click on a duck */
int click_duck(param_t *param, object_t **mini_hunter, int sprite);
/* moove the duck && dog sprite */
int move_sprites(param_t *param, object_t **mini_hunter, info_t *speed);
/* check if the score of kill is reached */
int analyse_mission(info_t *speed);

/* mini fight game */
int mini_fight(param_t *param, all_obj_t *all_obj);
void clock_ennemi(param_t *param, all_obj_t *all_obj);
void clock_marvin(all_obj_t *all_obj, mini_fight_t *fight);
int clock_fantom(all_obj_t *all_obj, mini_fight_t *fight, int *status, int a);
int move_char(all_obj_t *all_obj ,mini_fight_t *fight, int *status);
void print_texts_fight(sfRenderWindow *w, text_t **texts, mini_fight_t *fight);
int choose_fight(param_t *param, all_obj_t *all_obj, mini_fight_t *fight, int *status);
int defendre(param_t *param, all_obj_t *all_obj, mini_fight_t *fight, int *status);
int attaquer(param_t *param, all_obj_t *all_obj, mini_fight_t *fight, int *status);
void draw_later(all_obj_t *all_obj);
void win_lose(all_obj_t *all_obj, mini_fight_t *fight, int *status);
void win(all_obj_t *all_obj, int *status);
void lose(all_obj_t *all_obj, int *status);
void end(all_obj_t *all_obj);
mini_fight_t *create_fight(void);

char *itostr(int nb);
char *my_strncat(char *dest, char *src);
text_t **handle_text(void);
void print_texts(sfRenderWindow *w, text_t **texts, info_t *speed);

#endif /* !MINI_GAME_H_ */
