/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-gurvan.le-letty
** File description:
** text
*/

#include <stdlib.h>
#include "my_rpg.h"

text_t *create_text(char const *font_type, sfColor color, sfVector2f position,
int size)
{
    text_t *texts = malloc(sizeof(text_t));

    if (texts == NULL)
        return (NULL);
    texts->text = sfText_create();
    texts->font = sfFont_createFromFile(font_type);
    sfText_setFont(texts->text, texts->font);
    sfText_setColor(texts->text, color);
    sfText_setPosition(texts->text, position);
    sfText_setCharacterSize(texts->text, size);
    return (texts);
}