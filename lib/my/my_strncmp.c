/*
** EPITECH PROJECT, 2021
** my_strncmp
** File description:
** my_strncmp
*/

int my_strncmp(char const *s1, char const *s2, int lenth)
{
    for (int i = 0; (s1[i] != '\0' || s2[i] != '\0') && i != lenth; i++)
        if (s1[i] != s2[i])
            return 0;
    return 1;
}