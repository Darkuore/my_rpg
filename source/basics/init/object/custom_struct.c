/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** custom_struct
*/

#include <stdlib.h>
#include "object.h"

static char const *ROAD = "assets/sprite/custom/road.conf";
static char const *TREE = "assets/sprite/custom/tree.conf";
static char const *WATER = "assets/sprite/custom/water.conf";

cust_map_t *create_cust_struct(void)
{
    cust_map_t *cust_struct = NULL;

    cust_struct = malloc(sizeof(cust_map_t));
    if (cust_struct == NULL)
        return (NULL);
    cust_struct->cust_road = create_object(ROAD);
    cust_struct->cust_tree = create_object(TREE);
    cust_struct->cust_water = create_object(WATER);
    if (cust_struct->cust_road == NULL || cust_struct->cust_tree == NULL
    || cust_struct->cust_water == NULL)
        return (NULL);
    return (cust_struct);
}

void destroy_cust_struct(cust_map_t *cust_struct)
{
    destroy_obj(cust_struct->cust_road);
    destroy_obj(cust_struct->cust_tree);
    destroy_obj(cust_struct->cust_water);
    free(cust_struct);
}