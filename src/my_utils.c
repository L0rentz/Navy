/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** my_utils
*/

#include "utils.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_strlen(char *str)
{
    int i = 0;
    for (; str != NULL && str[i] != '\0'; i++);
    return (i);
}

void my_putstr(char *str)
{
    if (str != NULL)
        write(1, str, my_strlen(str));
}

char *my_strcpy(char *dest, char *src)
{
    int i = 0;
    for (; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    if (nb >= 0) {
        if (nb >= 10) {
            my_put_nbr(nb / 10);
            my_putchar(nb % 10 + '0');
        }
        else
            my_putchar(nb % 10 + '0');
    }
    return (0);
}