/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** load_map
*/

#include "utils.h"

void fill_map(char **map, int line)
{
    if (line == 0) my_strcpy(map[line], " |A B C D E F G H\n");
    if (line == 1) my_strcpy(map[line], "-+---------------\n");
    if (line == 2) my_strcpy(map[line], "1|. . . . . . . .\n");
    if (line == 3) my_strcpy(map[line], "2|. . . . . . . .\n");
    if (line == 4) my_strcpy(map[line], "3|. . . . . . . .\n");
    if (line == 5) my_strcpy(map[line], "4|. . . . . . . .\n");
    if (line == 6) my_strcpy(map[line], "5|. . . . . . . .\n");
    if (line == 7) my_strcpy(map[line], "6|. . . . . . . .\n");
    if (line == 8) my_strcpy(map[line], "7|. . . . . . . .\n");
    if (line == 9) my_strcpy(map[line], "8|. . . . . . . .\n");
}

void fill_ships_col(char **map, char min, char max, int line)
{
    char ship = max + 1 - min + 48;
    for (int i = min * 2 - 2; i != max * 2; i += 2)
        map[line][i] = ship;
}

void fill_ships_line(char **map, char min, char max, int col)
{
    char ship = max + 1 - min + 48;
    col = col * 2 - 2;
    for (int i = min; i != max + 1; i++)
        map[i][col] = ship;
}

char **load_map(char *pos, int who)
{
    char **map = malloc(sizeof(char *) * 11);
    for (int i = 0; i != 10; i++) {
        map[i] = malloc(sizeof(char) * 19);
        fill_map(map, i);
    } map[10] = NULL;
    if (who == 0) {
        int fd = open(pos, O_RDONLY), col1 = 0, line1 = 0, col2 = 0, line2 = 0;
        char *str = get_next_line(fd);
        for (int i = 0; i != 4; str = get_next_line(fd), i++) {
            col1 = str[2] - 63, col2 = str[5] - 63;
            line1 = str[3] - 47, line2 = str[6] - 47;
            if (col1 > col2) fill_ships_col(map, col2, col1, line1);
            if (col1 < col2) fill_ships_col(map, col1, col2, line1);
            if (line1 > line2) fill_ships_line(map, line2, line1, col1);
            if (line1 < line2) fill_ships_line(map, line1, line2, col1);
            free(str);
        }
    } return (map);
}

void free_map(char **my_map, char **his_map)
{
    for (int i = 0; my_map[i] != NULL; i++) {
        free(my_map[i]);
        free(his_map[i]);
        my_map[i] = NULL;
        his_map[i] = NULL;
    } free(my_map);
    free(his_map);
    my_map = NULL;
    his_map = NULL;
}