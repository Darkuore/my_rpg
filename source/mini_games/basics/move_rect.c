/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** moove_rect
*/

#include "my_include.h"

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    rect->left = rect->left + offset;
    if (rect->left >= max_value)
        rect->left = 0;
}