/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** set_pos, set_rect
*/

#include <stdlib.h>
#include "my.h"
#include "my_include.h"

static sfIntRect error_rect = {-1, -1, -1, -1};

static char **make_all_info(char *info)
{
    char **all_info = NULL;

    all_info = my_str_to_word_arr(info, ',');
    if (all_info == NULL)
        return (NULL);
    for (int i = 0; all_info[i] != NULL; i++)
        if (my_str_isnum(all_info[i]) == 0)
            return (NULL);
    return (all_info);
}

sfIntRect set_rect(char *info)
{
    char **all_info = NULL;
    sfIntRect rect = {0, 0, 0, 0};

    all_info = make_all_info(info);
    if (all_info == NULL)
        return (error_rect);
    rect.left = my_getnbr(all_info[0]);
    rect.top = my_getnbr(all_info[1]);
    rect.width = my_getnbr(all_info[2]);
    rect.height = my_getnbr(all_info[3]);
    free_arr(all_info);
    return (rect);
}

static sfVector2f set_one_vector(float x, float y)
{
    sfVector2f vector = {0, 0};

    vector.x = x;
    vector.y = y;
    return (vector);
}

sfVector2f *set_vector(char *info, char *second_info)
{
    char **all_info = NULL;
    sfVector2f *vector = NULL;

    all_info = make_all_info(info);
    if (all_info == NULL)
        return (NULL);
    vector = malloc(sizeof(sfVector2f) * 3);
    if (vector == NULL)
        return (NULL);
    vector[0] = set_one_vector(my_atof(all_info[0]), my_atof(all_info[1]));
    vector[1] = set_one_vector(my_atof(all_info[0]), my_atof(all_info[1]));
    free_arr(all_info);
    all_info = make_all_info(second_info);
    if (all_info == NULL)
        return (NULL);
    vector[2] = set_one_vector(my_atof(all_info[0]), my_atof(all_info[1]));
    free_arr(all_info);
    return (vector);
}