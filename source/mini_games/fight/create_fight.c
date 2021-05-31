/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-gurvan.le-letty
** File description:
** create_hunter
*/

#include <stdlib.h>
#include "my_rpg.h"

mini_fight_t *create_fight(void)
{
    mini_fight_t *fight = malloc(sizeof(mini_fight_t));

    fight->pv = malloc(2 * sizeof(int));
    fight->clock_marvin = sfClock_create();
    fight->clock_fantom = sfClock_create();
    fight->second_marvin = 0;
    fight->second_fantom = 0;
    fight->pv[0] = 200;
    fight->pv[1] = 200;
    return (fight);
}