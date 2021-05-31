/*
** EPITECH PROJECT, 2021
** create_window
** File description:
** create_window
*/

#include "my_include.h"

sfRenderWindow *create_window(void)
{
    sfRenderWindow *window = NULL;
    sfVideoMode video_mode = { 1920, 1080, 32 };

    window = sfRenderWindow_create(video_mode, "MY_RPG",
        sfDefaultStyle, NULL);
    return (window);
}