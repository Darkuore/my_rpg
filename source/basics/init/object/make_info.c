/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** make_info
*/

#include <stdlib.h>
#include "my.h"
#include "object.h"

char *make_one_info(char *str, char **info)
{
    int i = 0;
    char *buff = NULL;

    for (i = 0; info[i] != NULL; i++)
        if (my_strncmp(str, info[i], my_strlen(str)) == 1) {
            buff = take_info(str, info[i]);
            break;
        }
    return (buff);
}

static void clean_info(char **clear_info, char **info)
{
    clear_info[0] = make_one_info("SPRITE=", info);
    clear_info[1] = make_one_info("RECT=", info);
    clear_info[2] = make_one_info("POS=", info);
    clear_info[3] = make_one_info("SCALE=", info);
    clear_info[4] = make_one_info("ZOOM_SCALE=", info);
    clear_info[5] = make_one_info("ZOOM_POS=", info);
}

char **make_info(char *info)
{
    char **all_info = NULL;
    char **clear_info = NULL;
    int len = 0;

    all_info = my_str_to_word_arr(info, ' ');
    if (all_info == NULL)
        return (NULL);
    len = my_arrlen(all_info);
    clear_info = malloc(sizeof(char *) * (len + 1));
    if (clear_info == NULL)
        return (NULL);
    clear_info[len] = NULL;
    clean_info(clear_info, all_info);
    free_arr(all_info);
    for (int i = 0; i != len; i++)
        if (clear_info[i] == NULL)
            return (NULL);
    return (clear_info);
}