/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** main
*/

#include "my.h"

int game_loop(char **av, int ac, int *pid, int *win)
{
    char **my_map = load_map(av[ac - 1], 0);
    char **his_map = load_map(av[ac - 1], 1);
    if (pid[0] == 0) pid[1] = my_atoi(av[1]);
    for (int turn = 0, hit = 0; 1;) {
        print_map(my_map, his_map);
        if (check_lose_win(my_map, win) == 1) break;
        if (turn == 0)
            hit = turn_zero(pid, my_map, &turn, his_map);
        if (hit == 1) {
            free_map(my_map, his_map);
            return (1);
        } if (turn == 1)
            hit = turn_one(pid, my_map, &turn, his_map);
        if (hit == 1) {
            free_map(my_map, his_map);
            return (1);
        } if (hit == 2) break;
    } if (*win == 0 && pid[0] == 0) print_map(my_map, his_map);
    free_map(my_map, his_map);
    return (0);
}

int main(int ac, char **av)
{
    sig = -5;
    if (ac == 1 || ac > 3) return (84);
    if (ac == 2 && my_strlen(av[1]) == 2 && av[1][0] == '-' && av[1][1] == 'h')
        write_info();
    int win = 0;
    if (check_pid(ac, av) == 1) return (84);
    else {
        if (check_ships_positions(av[ac - 1]) == 1) return (84);
        int pid[2] = {write_pid(ac, av), 0};
        if (pid[0] == 1) return (84);
        if (game_loop(av, ac, pid, &win) == 1) return (84);
    }
    if (win == 1) {
        my_putstr("\nEnemy won\n\n");
        return (1);
    } my_putstr("\nI won\n\n");
    return (0);
}
