/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** main
*/

#include "my.h"
#include "my_rpg.h"

char const *HELPER = "assets/helper.txt";

int main (int ac, char const * const *av, char **env)
{
    if (*env == NULL)
        return (84);
    if (ac == 2 && my_strcmp(av[1], "-h") == 1)
        return (display_helper(HELPER));
    (void)av;
    return (init_rpg());
}