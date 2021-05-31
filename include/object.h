/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** object
*/

#ifndef OBJECT_H_
#define OBJECT_H_

#include "my_include.h"

/* object struct for a sprite with all pos scale, text, rect && count */
typedef struct object_s
{
    sfSprite *sprite;
    sfTexture *text;
    sfIntRect rect;
    sfVector2f *pos;
    sfVector2f *scale;
    int count_key;
} object_t;

/* text struct with the text && the font */
typedef struct text_s
{
    sfText *text;
    sfFont *font;
}text_t;

/* cust_map struct with all object of the customization of the map */
typedef struct cust_map_s
{
    object_t **cust_road;
    object_t **cust_water;
    object_t **cust_tree;
} cust_map_t;

/* all object struct with all sprite of all the game && the text to print */
typedef struct all_obj_s
{
    object_t **main_menu;
    object_t **map;
    object_t **cust_map;
    cust_map_t *cust_struct;
    object_t **mini_hunter;
    object_t **mini_fight;
    object_t **perso;
    object_t **game_menu;
    object_t **setting_menu;
    object_t **how_to_play;
    text_t **texts;
} all_obj_t;

/* set_file, to read && put the buffer into 2d array */
char **set_file(char const *filepath, char delim);

/* take_info from a str with a prefixe to skip */
char *take_info(char const *prefixe, char *str);

/* make_one_info */
char *make_one_info(char *str, char **info);
/* make_info from a line of a .conf file into a 2d array*/
char **make_info(char *info);

/* set_rect from a str into a 2d array and put it in int into a rect struct */
sfIntRect set_rect(char *info);

/* set_vector* from plurial info into 2d arrays and put them in float into vector struct */
sfVector2f *set_vector(char *info, char *second_info);

/* create_object into object** from a .conf file with all info */
object_t **create_object(char const *filepath);
/* destroy a object** */
void destroy_obj(object_t **obj);

/* create_text and put it into a text struct */
text_t **handle_text(void);
text_t *create_text(char const *font_type, sfColor color, sfVector2f position, int size);

/* create_cust_struct with object struct** */
cust_map_t *create_cust_struct(void);
/* destroy_cust_struct */
void destroy_cust_struct(cust_map_t *cust_struct);

/* create all_obj struct with all object** && text */
all_obj_t *create_all_obj(void);
/* destroy_all_obj struct */
void destroy_all_obj(all_obj_t *all_obj);

#endif /* !OBJECT_H_ */