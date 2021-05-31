/*
** EPITECH PROJECT, 2020
** POOL DAY 09
** File description:
** my.h
*/

#ifndef DICO
#define DICO

#define CTOI(x) (x - '0')
#define ITOC(x) (x + '0')

void my_putchar(char c);
int my_put_nbr(int nb);
void my_putstr(char const *str);
void my_puterror(char const *str);
int my_strlen(char const *str);
int my_arrlen(char **arr);
int my_getnbr(char const *str);
float my_atof(char const *str);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int lenth);
char *my_strcpy(char *dest, char const *src);
char *my_strdup(char const *src);
char *my_revstr(char *str);
char *my_strcat(char *dest, char const *src);
int my_str_isnum(char const *str);
char *read_file(char const *filepath);
char **my_str_to_word_arr(char *str, char delim);
char **malloc_arr(int lines, int cols);
void free_arr(char **arr);
int display_helper(char const *filepath);

#endif
