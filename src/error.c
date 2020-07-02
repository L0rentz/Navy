/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** error
*/

#include "utils.h"

int check_pid(int ac, char **av)
{
    if (ac != 3) return (0);
    int i = 0;
    for (; av[1][i] != '\0'; i++) {
        if (av[1][i] < '0' || av[1][i] > '9')
            return (1);
    } return (0);
}