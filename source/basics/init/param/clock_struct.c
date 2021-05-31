/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** clock
*/

#include <stdlib.h>
#include "param.h"

static my_clock_t *create_one_clock(void)
{
    my_clock_t *clock = NULL;

    clock = malloc(sizeof(my_clock_t));
    if (clock == NULL)
        return (NULL);
    clock->clock = sfClock_create();
    clock->second = 0;
    return (clock);
}

my_clock_t **create_clock(void)
{
    my_clock_t **clock = NULL;

    clock = malloc(sizeof(my_clock_t *) * 5);
    if (clock == NULL)
        return (NULL);
    clock[4] = NULL;
    for (int i = 0; i != 4; i++) {
        clock[i] = create_one_clock();
        if (clock[i] == NULL)
            return (NULL);
    }
    return (clock);
}

void destroy_clock(my_clock_t **clock)
{
    for (int i = 0; clock[i] != NULL; i++) {
        sfClock_destroy(clock[i]->clock);
        free(clock[i]);
    }
    free(clock);
}