/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** parse_map
*/

#include "utils.h"

void check_str(char *str, char *err, int i, char *tab)
{
    if (str[0] < '0' || str[0] > '9')
        *err = 1;
    for (; i != 4; i++)
        if (tab[i] == str[0]) {
            tab[i] = '\0';
            break;
        }
    if (str[1] != ':' || str[4] != ':' || i == 4)
        *err = 1;
    if ((str[2] < 'A' || str[2] > 'H') && (str[5] < 'A' || str[5] > 'H'))
        *err = 1;
    if ((str[3] < '1' || str[3] > '8') && (str[6] < '1' || str[8] > '8'))
        *err = 1;
    if (str[2] == str[5] && ABS(str[3] - str[6]) + 1 != str[0] - 48)
        *err = 1;
    else if (str[3] == str[6] && ABS(str[2] - str[5]) + 1 != str[0] - 48)
        *err = 1;
    if (str[2] != str[5] && str[3] != str[6])
        *err = 1;
}

int check_ships_positions(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char *str = get_next_line(fd);
    char tab[4] = {'2', '3', '4', '5'};
    char err = 0;
    int len = 0;
    for (int i = 0; str != NULL; len++, i = 0) {
        if (my_strlen(str) != 7 || len > 3)
            err = 1;
        check_str(str, &err, i, tab);
        free(str);
        str = get_next_line(fd);
    } free(str);
    close(fd);
    if (len < 4)
        err = 1;
    if (err == 1)
        return (1);
    return (0);
}