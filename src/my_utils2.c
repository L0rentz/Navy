/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** my_utils2
*/

#include "utils.h"

int my_atoi(char const *str)
{
    int i = 0;
    int result = 0;
    int check = 0;
    if (str == NULL || str[0] == '\0' || (str[0] > '9' && str[0] < '0'))
        return (0);
    if (str[0] == '-' && (str[1] <= '9' && str[1] >= '0')) {
        check++;
        i++;
    }
    if (str[0] == '+' && (str[1] <= '9' && str[1] >= '0'))
        i++;
    for (; str[i] != '\0' && (str[i] <= '9' && str[i] >= '0'); i++) {
        result += str[i] - '0';
        if (str[i+1] <= '9' && str[i+1] >= '0')
            result *= 10;
    }
    if (check == 1)
        result *= -1;
    return (result);
}

char *my_revstr(char *str)
{
    int len = my_strlen(str) - 1;
    char temp;

    for (int i = 0; i < len; i++) {
        temp = str[i];
        str[i] = str[len];
        str[len] = temp;
        len--;
    }
    return (str);
}

char *strnbr(int n)
{
    int modulo, a = 10, i = 0;
    char *str = malloc(10);
    if (n == 0)
        str[i++] = n + 48;
    for (; n > 0;) {
        if (n < 10) {
            str[i++] = (48 + n);
            n = 0;
        }
        else {
            modulo = (n % a);
            n = (n - modulo) / a;
            str[i++] = 48 + modulo;
        }
    }
    str[i] = '\0';
    my_revstr(str);
    return (str);
}