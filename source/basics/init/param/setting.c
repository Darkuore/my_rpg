/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** setting
*/

#include <stdlib.h>
#include "my.h"
#include "param.h"
#include "object.h"

static char **clean_info(char **info)
{
    char **clear_info = NULL;
    int len = 0;

    len = my_arrlen(info);
    clear_info = malloc(sizeof(char *) * (len + 1));
    if (clear_info == NULL)
        return (NULL);
    clear_info[len] = NULL;
    clear_info[0] = make_one_info("VOLUME=", info);
    clear_info[1] = make_one_info("FRAMERATE=", info);
    for (int i = 0; i != len; i++)
        if (clear_info[i] == NULL)
            return (NULL);
    return (clear_info);
}

int get_setting(param_t *param, char const *filepath)
{
    char *buff = NULL;
    char **info = NULL;
    char **clear_info = NULL;

    buff = read_file(filepath);
    if (buff == NULL)
        return (84);
    info = my_str_to_word_arr(buff, ' ');
    free(buff);
    if (info == NULL)
        return (84);
    clear_info = clean_info(info);
    free_arr(info);
    if (clear_info == NULL)
        return (84);
    param->framerate = my_getnbr(clear_info[1]);
    param->volume = my_getnbr(clear_info[0]);
    free_arr(clear_info);
    return (0);
}