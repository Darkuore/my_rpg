/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-gurvan.le-letty
** File description:
** print_texts
*/

#include "my_rpg.h"
#include <stdio.h>
#include <stdlib.h>

void print_texts_fight(sfRenderWindow *w, text_t **texts, mini_fight_t *fight)
{
    char *marvin = my_strncat("Marvin: ", itostr(fight->pv[0]));
    char *fantom = my_strncat("Fantom: ", itostr(fight->pv[1]));

    sfText_setString(texts[5]->text, marvin);
    sfText_setString(texts[6]->text, fantom);
    sfRenderWindow_drawText(w, texts[5]->text, NULL);
    sfRenderWindow_drawText(w, texts[6]->text, NULL);
}