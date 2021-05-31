/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** param
*/

#include <stdlib.h>
#include "my.h"
#include "param.h"
#include "object.h"

char const *SETTING = "assets/setting.conf";

static int set_status(param_t *param)
{
    int size = 3;

    param->status = malloc(sizeof(bool) * (size));
    if (param->status == NULL)
        return (84);
    for (int i = 0; i != size; i++)
        param->status[i] = false;
    return (0);
}

static void set_music(param_t *param, char const *musicpath)
{
    param->music = sfMusic_createFromFile(musicpath);
    sfMusic_setVolume(param->music, param->volume);
    sfMusic_setLoop (param->music, true);
}

param_t *create_param(char const *mappath, char const *musicpath)
{
    param_t *param = NULL;

    param = malloc(sizeof(param_t));
    if (param == NULL)
        return (NULL);
    param->window = NULL;
    param->window = create_window();
    param->clock = create_clock();
    if (param->clock == NULL)
        return (NULL);
    param->map = set_file(mappath, '\n');
    if (param->map == NULL)
        return (NULL);
    if (get_setting(param, SETTING) == 84)
        return (NULL);
    if (set_status(param) == 84)
        return (NULL);
    param->view = sfView_create();
    set_music(param, musicpath);
    return (param);
}

void destroy_param(param_t *param)
{
    sfRenderWindow_destroy(param->window);
    destroy_clock(param->clock);
    free_arr(param->map);
    sfMusic_destroy(param->music);
    sfView_destroy(param->view);
    free(param->status);
    free(param);
}