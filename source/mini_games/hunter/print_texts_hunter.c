/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-gurvan.le-letty
** File description:
** print_texts
*/

#include "my_rpg.h"
#include <stdio.h>
#include <stdlib.h>

void print_texts(sfRenderWindow *w, text_t **texts, info_t *speed)
{
    int i = 0;
    char *blue = my_strncat("Bleu :", itostr(speed->count[2]));
    char *red = my_strncat("Rouge :", itostr(speed->count[3]));
    char *green = my_strncat("Vert :", itostr(speed->count[4]));
    char *black = my_strncat("Noir :", itostr(speed->count[5]));
    char *total = my_strncat("Total : ", itostr(speed->count[0]));

    sfText_setColor(texts[3]->text, sfColor_fromRGB(70, 131, 23));
    sfText_setString(texts[0]->text, red);
    sfText_setString(texts[1]->text, blue);
    sfText_setString(texts[2]->text, black);
    sfText_setString(texts[3]->text, green);
    sfText_setString(texts[4]->text, total);
    while (i < 5) {
        sfRenderWindow_drawText(w, texts[i]->text, NULL);
        i++;
    }
}