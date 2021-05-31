/*
** EPITECH PROJECT, 2021
** my_atof
** File description:
** my_atof
*/

char *my_revstr(char *str);

static int is_num(char c)
{
    if (c == '.')
        return (2);
    if (c >= '0' && c <= '9')
        return (1);
    else
        return (0);
}

static float fill_decimal(char const *str)
{
    float res = 0;
    int p = 0;

    my_revstr((char *)str);
    for (int i = 0; str[i] != '.'; i++) {
        p = is_num(str[i]);
        if (p == 1)
            res = (res + (str[i] - '0')) / 10;
        else
            break;
    }
    return (res);
}

float my_atof(char const *str)
{
    float res = 0;
    int sign = 1;

    for (int i = 0, p = 0; str[i] != '\0'; i++) {
        while (str[i] == '-' || str[i] == '+') {
            if (str[i] == '-')
                sign *= (-1);
            i++;
        }
        p = is_num(str[i]);
        if (p == 2) {
            res += fill_decimal(str);
            break;
        }
        else if (p == 1)
            res = res * 10 + (str[i] - '0');
        else
            break;
    }
    return (res * sign);
}