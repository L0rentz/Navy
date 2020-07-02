/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** player_turn
*/

#include "my.h"

int check_lose_win(char **my_map, int *win)
{
    int x = 0;
    for (int i = 0; my_map[i] != NULL; i++) {
        for (int j = 1; my_map[i][j] != '\0'; j++)
            if (my_map[i][j] == '2' || my_map[i][j] == '3'
            || my_map[i][j] == '4' || my_map[i][j] == '5')
                x++;
    }
    if (x == 0) {
        *win = 1;
        return (1);
    } return (0);
}

int turn_zero_defense(int *turn, int *pid, char **my_map, int hit)
{
    if (hit == 14) return (2);
    if (*turn == 0 && pid[0] == 0) {
        char *str = NULL;
        int err = 0;
        my_putstr("\nwaiting for enemy's attack...\n");
        str = receive_attack();
        my_putstr(str);
        if (check_if_hit(my_map, str) == 1) {
            my_putstr(": hit\n");
            print_hit(my_map, 'x', str);
            err = send_hit_confirmation(pid[1], 1);
        } else {
            my_putstr(": missed\n");
            print_hit(my_map, 'o', str);
            send_hit_confirmation(pid[1], 0);
        } if (err == -1) return (1);
        *turn = 1;
        free (str);
    } return (0);
}

int turn_zero(int *pid, char **my_map, int *turn, char **his_map)
{
    static int hit = 0, victory = 0;
    if (hit == 14) return (2);
    if (*turn == 0 && pid[0] != 0) {
        char *str = NULL;
        my_putstr("\nattack: "), str = get_next_line(0);
        for (; check_attack(str) == 1; str = get_next_line(0))
            my_putstr("wrong position\n"), my_putstr("attack: "), free(str);
        my_putstr(str);
        if (send_attack(pid[0], str) == 1) {
            free(str);
            return (1);
        } str[0] += 16;
        if (receive_hit_confirmation() == 1) {
            hit++, my_putstr(": hit\n"), print_hit(his_map, 'x', str);
        } else my_putstr(": missed\n"), print_hit(his_map, 'o', str);
        free(str), *turn = 1;
    } victory = turn_zero_defense(turn, pid, my_map, hit);
    if (victory == 1) return (1);
    else if (victory == 2) return (2);
    return (0);
}

int turn_one_defense(int *turn, int his_pid, char **my_map, int hit)
{
    if (hit == 14) return (2);
    if (*turn == 1 && his_pid != 0) {
        char *str = NULL;
        int err = 0;
        my_putstr("\nwaiting for enemy's attack...\n");
        str = receive_attack();
        my_putstr(str);
        if (check_if_hit(my_map, str) == 1) {
            my_putstr(": hit\n");
            print_hit(my_map, 'x', str);
            err = send_hit_confirmation(his_pid, 1);
        } else {
            print_hit(my_map, 'o', str);
            my_putstr(": missed\n");
            send_hit_confirmation(his_pid, 0);
        } if (err == -1) return (1);
        *turn = 0;
        free (str);
    } return (0);
}

int turn_one(int *pid, char **my_map, int *turn, char **his_map)
{
    static int hit = 0, victory = 0;
    if (hit == 14) return (2);
    if (*turn == 1 && pid[0] == 0) {
        char *str = NULL;
        my_putstr("\nattack: "), str = get_next_line(0);
        for (; check_attack(str) == 1; str = get_next_line(0))
            my_putstr("wrong position\n"), my_putstr("attack: "), free(str);
        my_putstr(str);
        if (send_attack(pid[1], str) == 1) {
            free(str);
            return (1);
        } str[0] += 16;
        if (receive_hit_confirmation() == 1) {
            hit++, my_putstr(": hit\n"), print_hit(his_map, 'x', str);
        } else my_putstr(": missed\n"), print_hit(his_map, 'o', str);
        free(str), *turn = 0;
    } victory = turn_one_defense(turn, pid[0], my_map, hit);
    if (victory == 1) return (1);
    else if (victory == 2) return (2);
    return (0);
}