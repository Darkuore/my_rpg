/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** param
*/

#ifndef PARAM_H_
#define PARAM_H_

#include "my_include.h"

/* clock struct in param struct */
typedef struct my_clock_s
{
    sfClock *clock;
    sfTime time;
    float second;
} my_clock_t;

/* param struct */
typedef struct param_s
{
    sfRenderWindow *window;
    int framerate;
    sfEvent event;
    my_clock_t **clock;
    sfVector2i mouse_coord;
    bool *status;
    char **map;
    sfMusic *music;
    int volume;
    sfView *view;
} param_t;

/* create CSFML window */
sfRenderWindow *create_window(void);

/* create the clock struct with the clock, time, second */
my_clock_t **create_clock(void);
/* destroy clock struct */
void destroy_clock(my_clock_t **clock);

/* get setting info from a .conf file */
int get_setting(param_t *param, char const *filepath);

/* create the param struct with window, event, the map, the music && the clocks */
param_t *create_param(char const *mappath, char const *musicpath);
/* destroy the param struct */
void destroy_param(param_t *param);

#endif /* !PARAM_H_ */