/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** printer
*/

#include "my.h"

void print_hit(char **map, char hit, char *pos)
{
    int line = (pos[1] - 48) + 1;
    int col = (pos[0] - 64) * 2;
    map[line][col] = hit;
}

int write_pid(int ac, char **av)
{
    if (ac != 2 && my_atoi(av[1]) <= 0) return (1);
    if (ac == 2) {
        my_putstr("my_pid: ");
        my_put_nbr(getpid());
        my_putstr("\nwaiting for enemy connection...\n\n");
        int pid = receive_pid();
        my_putstr("enemy connected\n");
        return (pid);
    } else {
        if (send_pid(av[1]) == 1) return (1);
        my_putstr("my_pid: ");
        my_put_nbr(getpid());
        my_putstr("\nsuccessfully connected\n");
    } return (0);
}

void write_info(void)
{
    my_putstr("USAGE\n     ./navy [first_player_pid] navy_positions\n");
    my_putstr("DESCRIPTION\n     first_player_pid: only for the 2nd player.");
    my_putstr(" pid of the first player.\n     navy_positions: file");
    my_putstr(" representing the positions of the ships.\n");
}

void print_map(char **my_map, char **his_map)
{
    my_putstr("\nmy_positions:\n");
    for (int i = 0; my_map[i] != NULL; i++)
        my_putstr(my_map[i]);
    my_putstr("\nenemy's positions:\n");
    for (int i = 0; his_map[i] != NULL; i++)
        my_putstr(his_map[i]);
}