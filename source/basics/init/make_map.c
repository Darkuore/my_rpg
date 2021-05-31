/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** make_map
*/

#include <stdlib.h>
#include "my.h"
#include "my_rpg.h"

static int count_key(char **map, int key)
{
    int count = 0;

    for (int i = 0; map[i] != NULL; i++)
        for (int j = 0; map[i][j] != '\0'; j++)
            if (map[i][j] == ITOC(key))
                count++;
    return (count);
}

static void make_one_road(char **map, object_t *obj, int key)
{
    int count = 0;
    int nbr = 0;

    count = count_key(map, key);
    free(obj->pos);
    obj->pos = malloc(sizeof(sfVector2f) * count);
    obj->count_key = count;
    for (int i = 0; map[i] != NULL; i++)
        for (int j = 0; map[i][j] != '\0'; j++)
            if (map[i][j] == ITOC(key)) {
                obj->pos[nbr].x = j * 48;
                obj->pos[nbr].y = i * 48;
                nbr++;
            }
}

void make_map(char **map, object_t **obj)
{
    for (int i = 2; obj[i] != NULL; i++)
        make_one_road(map, obj[i], i);
}