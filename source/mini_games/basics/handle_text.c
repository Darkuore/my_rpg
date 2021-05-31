/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-gurvan.le-letty
** File description:
** handle_text
*/

#include "my_rpg.h"
#include <stdio.h>
#include <stdlib.h>

static char const *hunter = "assets/fonts/regular.ttf";
static char const *fight = "assets/fonts/forward.ttf";
static char const *dialogue = "assets/fonts/TravelingTypewriter.ttf";

text_t **handle_text(void)
{
    text_t **texts = malloc(sizeof(text_t) * 8);

    if (texts == NULL)
        return (NULL);
    texts[8] = NULL;
    texts[0] = create_text(hunter, sfRed, (sfVector2f){460, 145}, 20);
    texts[1] = create_text(hunter, sfBlue, (sfVector2f){660, 145}, 20);
    texts[2] = create_text(hunter, sfBlack, (sfVector2f){860, 145}, 20);
    texts[3] = create_text(hunter, sfGreen, (sfVector2f){1060, 145}, 20);
    texts[4] = create_text(hunter, sfBlack, (sfVector2f){1370, 145}, 20);
    texts[5] = create_text(fight, sfWhite, (sfVector2f){1100, 630}, 30);
    texts[6] = create_text(fight, sfWhite, (sfVector2f){1100, 730}, 30);
    texts[7] = create_text(dialogue, sfWhite, (sfVector2f){650, 470}, 10);
    for (int i = 0; i != 8; i++)
        if (texts[i] == NULL)
            return (NULL);
    return (texts);
}